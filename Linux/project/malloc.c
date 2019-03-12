#include "malloc.h"
/*Modify Any parts above is illegal*/
/*只准修改以下内容 否则零分处理*/

typedef struct metadata_block {
    size_t size;
    size_t is_free;
    struct metadata_block *pre;
    struct metadata_block *next;
    void *begin;
}Metadata, *pMetadata;

static pMetadata _memory_head = NULL;

static void initMetadata(pMetadata p, size_t size, size_t is_free, pMetadata pre, pMetadata next) {
    p->size = size;
    p->is_free = is_free;
    p->pre = pre;
    p->next = next;
    p->begin = ((char *)p) + sizeof(Metadata);
}

void dataCopyTo(pMetadata p, pMetadata q) {//将p的数据存入q中
    char *ret_q = (char *)q->begin;
    char *ret_p = (char *)p->begin;
    for (size_t i = 0; i < p->size; i++) {
        *ret_q = *(ret_p + i);
        ret_q++;
    }
    q->is_free = 0;
}

void *mylloc(size_t sizes){
    if (_memory_head == NULL) {
        pMetadata p = sbrk(0);
        if (sbrk(sizes + sizeof(Metadata)) == (void *)(-1)) {
            return NULL;
        }
        initMetadata(p, sizes, 0, NULL, NULL);
        _memory_head = p;
        return p->begin;
    } else {
        pMetadata p = _memory_head, q;
        while (p) {
            if (p->is_free && p->size > (sizes + sizeof(Metadata))) {
                q = p + sizeof(Metadata) + sizes;//???
                initMetadata(q, p->size - sizes - sizeof(Metadata), 1, p, p->next);
                p->next = q;
                p->is_free = 0;
                return p->begin;
            }
            if (p->is_free && p->size >= sizes) {
                p->is_free = 0;
                return p->begin;
            }
            if (p->next == NULL) {
                q = sbrk(sizes + sizeof(Metadata));
                initMetadata(q, sizes, 0, p, NULL);
                return q->begin;
            }
            p = p->next;
        }
    }
}

void myfree(void *ptr){
    pMetadata p = _memory_head;
    while (p) {
        if (p->begin == ptr) {
            p->is_free = 1;
            if (p->pre && p->pre->is_free && p->next && p->next->is_free) {
                p->pre->size += sizeof(Metadata) * 2 + p->size + p->next->size;
                return ;
            }
            if (p->pre && p->pre->is_free) {
                p->pre->size += sizeof(Metadata) + p->size;
                return ;
            }
            if (p->next && p->next->is_free) {
                p->size += sizeof(Metadata) + p->next->size;
                return ;
            }
        }
        if (p->next == NULL) {
            return ;
        }
        p = p->next;
    }
}

void *mycalloc(size_t numitems, size_t size){
    void *ret = mylloc(numitems * size);
    if (ret == NULL) {
        return NULL;
    }
    char *p = (char *)ret;
    size_t i = numitems * size;
    while (i--) {
        (*p) = 0;
        ++p;
    }
    return ret;
}

void *myrealloc(void *ptr, size_t size){
    pMetadata p = _memory_head;
    while (p) {
        if (p->begin == ptr) {
            if (size < p->size) {
                return p->begin;
            }
            if (p->next && p->next->is_free && ((p->size + p->next->size) > size)) {//该节点后面有空间
                pMetadata q = p + sizeof(Metadata) + size;
                initMetadata(q, p->size + sizeof(Metadata) + p->next->size - size, 1, p, p->next);
                p->next = q;
                p->size = size;
                return p->begin;
            }
            if (p->pre && p->pre->is_free && (p->pre->size + sizeof(Metadata) + p->size > size)) {//该节点前面有空间
                dataCopyTo(p, p->pre);
                p->pre->size += p->size + sizeof(Metadata);
                return p->pre->begin;
            }
            pMetadata q = _memory_head; //前后均无空间
            while (q) {
                if (q->is_free && q->size > size) {
                    dataCopyTo(p, q);
                    return q->begin;
                }
                if (q->next == NULL) {
                    pMetadata k = sbrk(size + sizeof(Metadata));
                    initMetadata(k, size, 0, q, NULL);
                    q->next = k;
                    dataCopyTo(p, k);
                    return k->begin;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
}
/*只准修改以上内容 否则零分处理*/
/*Modify Any parts below is illegal*/

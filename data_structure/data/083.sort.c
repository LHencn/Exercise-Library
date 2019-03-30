#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define GROUP_SIZE  1000

#define GROUP_COUNT 10

#define DATA_SIZE   16



struct count {

    char data[DATA_SIZE];

    int32_t num;

};



struct count count_group[GROUP_SIZE];

struct count count_buffer[GROUP_SIZE];



int comp_data(const void *v1, const void *v2)

{

    const struct count *p1, *p2;

    p1 = (const struct count *)v1;

    p2 = (const struct count *)v2;

    return memcmp(p1->data, p2->data, DATA_SIZE);

}



int comp_count(const void *v1, const void *v2)

{

    const struct count *p1, *p2;

    p1 = (const struct count *)v1;

    p2 = (const struct count *)v2;

    return p2->num - p1->num;

}





int sort_data(int n)

{

    qsort(count_group, n, sizeof(struct count), comp_data);

    return 0;

}



int uniq_data(int n)

{

    int i, j;

    char buf[DATA_SIZE];



    buf[DATA_SIZE - 1] = '\0';



    for (i = 0; i < n; ++i) {

        if (count_group[i].num == 0)

            continue;

        for (j = i + 1; j < n; ++j) {

            if (0 == comp_data(&count_group[i], &count_group[j])) {

                ++count_group[i].num;

                --count_group[j].num;

            } else {

                break;

            }

        }

    }



#if 0

    for (i = 0; i < n; ++i) {

        memcpy(buf, count_group[i].data, DATA_SIZE - 1);

        printf("%02d: data=[%s] (%03u)\n", i, buf, (unsigned)count_group[i].num);

    }

#endif



    return n;

}



int sort_count(int n)

{

    qsort(count_group, n, sizeof(struct count), comp_count);

    return 0;

}



int input_data(FILE *fp, int grp)

{

    fpos_t pos;

    int i, n, r;

    char buf[DATA_SIZE];



    buf[DATA_SIZE - 1] = '\0';



    for (i = 0; i < GROUP_SIZE; ++i) {

        count_group[i].num = 0;

    }



    pos = grp * DATA_SIZE * GROUP_SIZE;

    fsetpos(fp, &pos);



    n = GROUP_SIZE;

    for (i = 0; i < n; ++i) {

        r = fread(count_group[i].data, DATA_SIZE, 1, fp);

        if (r != 1)

            break;

        count_group[i].num = 1;

    }



    n = i;



#if 0

    for (i = 0; i < n; ++i) {

        memcpy(buf, count_group[i].data, DATA_SIZE - 1);

        printf("%02d: data=[%s] (%03u)\n", i, buf, (unsigned)count_group[i].num);

    }

#endif



    return n;

}



int output_data(int grp, int num)

{

    int i, n;

    FILE *fp;

    char name[] = "top10_00.txt";



    n = num;

    sprintf(name, "top10_%02d.txt", grp);

    fp = fopen(name, "wb");

    for (i = 0; i < n; ++i) {

        if (count_group[i].num > 0) {

            fwrite(&count_group[i], sizeof(struct count), 1, fp);

        }

    }

    fclose(fp);

}



int input_count(int grp, struct count *ctr)

{

    int i, n;

    FILE *fp;

    char name[] = "top10_00.txt";



    n = GROUP_SIZE;

    sprintf(name, "top10_%02d.txt", grp);

    fp = fopen(name, "rb");

    i = fread(ctr, sizeof(struct count), n, fp);

    fclose(fp);



    n = i;

    return n;

}



int merge_count(struct count *ctr1, int num1, struct count *ctr2, int num2)

{

    int i, j, m, n;



    n = num1;

    m = num2;

    for (i = 0; i < n; ++i) {

        if (ctr1[i].num == 0)

            continue;

        for (j = 0; j < m; ++j) {

            if (0 == comp_data(&ctr1[i], &ctr2[j])) {

                ctr1[i].num += ctr2[j].num;

                ctr2[j].num = 0;

            }

        }

    }



    return 0;

}



int update_count(int grp, struct count *ctr, int num)

{

    int i, n;

    FILE *fp;

    char name[] = "top10_00.txt";



    n = num;

    sprintf(name, "top10_%02d.txt", grp);

    fp = fopen(name, "wb");

    fwrite(ctr, sizeof(struct count), n, fp);

    fclose(fp);



    return n;

}



int output_count(FILE *fp, int num)

{

    int i, n;

    char buf[DATA_SIZE];



    buf[DATA_SIZE - 1] = '\0';



    n = num;



    for (i = 0; i < n; ++i) {

        if (count_group[i].num == 0)

            continue;

        fwrite(&count_group[i], sizeof(struct count), 1, fp);

    }



#if 0

    for (i = 0; i < n; ++i) {

        if (count_group[i].num == 0)

            continue;

        memcpy(buf, count_group[i].data, DATA_SIZE - 1);

        printf("count[%05d]: data=[%s]\n", (unsigned)count_group[i].num, buf);

    }

#endif

}



int build_count(void)

{

    int i, j, m1, m2, n;

    FILE *fp;

    char name[] = "count_01.txt";





    n = GROUP_COUNT;

    for (i = 0; i < n; ++i) {

        sprintf(name, "count_%02d.txt", i);

        fp = fopen(name, "wb");

        m1 = input_count(i, count_group);

        for (j = i + 1; j < n; ++j) {

            m2 = input_count(j, count_buffer);

            merge_count(count_group, m1, count_buffer, m2);

            update_count(j, count_buffer, m2);

        }

        sort_count(m1);

        output_count(fp, m1);

        fclose(fp);

    }





    return 0;

}



int get_top10(void)

{

    int i, j, n, m;

    FILE *fp;

    char buf[DATA_SIZE];

    char name[] = "count_01.txt";



    n = GROUP_COUNT;

    for (i = 0; i < n; i++) {

        count_group[i].num = 0;

    }



    j = 0;

    for (i = 0; i < n; i++) {

        sprintf(name, "count_%02d.txt", i);

        fp = fopen(name, "rb");

        m = fread(&count_group[j], sizeof(struct count), 10, fp);

        j += m;

        fclose(fp);

    }





    sort_count(j);



    if (j < 10) {

        n = j;

    } else {

        n = 10;

    }

    buf[DATA_SIZE - 1] = '\0';

    for (i = 0; i < n; ++i) {

        memcpy(buf, count_group[i].data, DATA_SIZE - 1);

        printf("count[%05d]: data=[%s]\n", (unsigned)count_group[i].num, buf);

    }

}



int gen_data(void)

{

    FILE *fp;

    int ch;

    int i, j, m, n;

    char data[DATA_SIZE];



    m = DATA_SIZE - 1;

    n = GROUP_SIZE * GROUP_COUNT;

    data[m] = '\0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';

    data[--m] = '0';



    srand(getpid());

    fp = fopen("top10.txt", "wb");

    for (i = 0; i < n; ++i) {

        for (j = 0; j < m; ++j) {

            while (!isdigit((ch = rand() % 256))) {

                ;

            }

            data[j] = ch;
        }
        fprintf(fp, "%s\n", data);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[])

{
    FILE *fp;
    int i, n, m;
    gen_data();
    fp = fopen("top10.txt", "rb");
    n = GROUP_COUNT;
    for (i = 0; i < n; ++i) {
        m = input_data(fp, i);
        sort_data(m);
        uniq_data(m);
        output_data(i, m);
    }
    fclose(fp);
    build_count();
    get_top10();
    
    return 0;
}

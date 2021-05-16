/*
    Examples with union usage and COPY macros.
*/

#include <stdlib.h>
#include <stdio.h>

#define FILL_UNION_MACRO(cd) { \
    cd.data.a.v2 = 30; \
    cd.data.b.v2 = 40; \
}

#define COPY_DATA_MACRO(src, dst) do { \
    (dst)->v1 = (src).v1; \
    (dst)->v2 = (src).v2; \
} while(0)

enum data_types {A, B} data_type;

struct TypeA {
    int v1;
    int v2;
    int v100500;
};

struct TypeB {
    int v100501;
    int v1;
    int v2;
};

struct TypeCommon {
    int v1;
    int v2;
};

struct ComplexData {
    enum data_types data_type;
    union {
        struct TypeA a;
        struct TypeB b;
    } data; // Access with complex_data.data.a or complex_data.data.b
};

struct TypeA adata = { 1, 2, 3 };
struct TypeB bdata = { 4, 5, 6 };

void fill_union(struct ComplexData *cdata, enum data_types data_type)
{
    switch (data_type)
    {
        case A:
            cdata->data.a.v1 = 10;
            break;
        case B:
            cdata->data.b.v1 = 20;
            break;
    }
}

void copy_data(struct TypeCommon *cdata, enum data_types data_type)
{
    switch (data_type)
    {
        case A:
            COPY_DATA_MACRO(adata, cdata);
            break;
        case B:
            COPY_DATA_MACRO(bdata, cdata);
            break;
    }
}

int main()
{
    struct ComplexData cdata;
    struct TypeCommon *common = malloc(sizeof(struct TypeCommon));

    fill_union(&cdata, A);
    printf("ComplexData v1 value: %d\n", cdata.data.a.v1);

    fill_union(&cdata, B);
    printf("ComplexData v1 value: %d\n", cdata.data.b.v1);

    FILL_UNION_MACRO(cdata);
    printf("ComplexData v2 value: %d\n", cdata.data.a.v2);
    printf("ComplexData v2 value: %d\n", cdata.data.b.v2);

    copy_data(common, A);
    printf("TypeCommon v1 = %d, v2 = %d\n", common->v1, common->v2);

    copy_data(common, B);
    printf("TypeCommon v1 = %d, v2 = %d\n", common->v1, common->v2);
}

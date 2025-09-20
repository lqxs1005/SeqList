#include <stdio.h>
#define MAX_SIZE 100

typedef struct list {
    int elements[MAX_SIZE], length;
} List;
List l; 

void init(List *l) {
    // 初始化: 创建一个空的顺序表
    l->length = 0;
}

int insert(List *l, int p, int x) {
    // 插入: 把新元素 x 插入到 p 位置 (等价于插入到第 p 个元素前)
    if (p < 0 || p > l->length) return -1; // 下标越界
    int i;
    for (i = l->length - 1; i >= p; --i) {
        l->elements[i + 1] = l->elements[i];
    }
    l->elements[p] = x;
    l->length++;
    return 0;
}

int search(List *l, int x) {
    // 顺序查找: 元素 x 第一次出现的位置
    int i;
    for (i = 0; i < l->length; ++i) {
        if (l->elements[i] == x) return i;
    }
    return -1;
}

int delete(List *l, int p) {
    // 删除: 删除第 p 个元素
    if (p < 0 || p >= l->length) return -1; // 下标越界
    int i;
    for (i = p + 1; i < l->length; ++i) {
        l->elements[i - 1] = l->elements[i];
    }
    l->length--;
    return 0;
}

void print(List *l) {
    if (l->length == 0) {
        printf("[Empty list]\n");
        return;
    }
    int i;
    for (i = 0; i < l->length; ++i) {
        printf("%d ", *(l->elements + i));
    }
    printf("\n");
}
int main() {
    List l;
    init(&l);
    insert(&l, 0, 1);
    insert(&l, 1, 2);
    insert(&l, 1, 3);
    print(&l); // 1 3 2
    printf("%d\n", search(&l, 3)); // 1
    delete(&l, 1);
    print(&l); // 1 2
    return 0;
}
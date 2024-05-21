

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 此处使用 C 语言的 typedef 定义数据类型

// #region define
#define MaxSize 50 // 此处使用 C 语言的宏
typedef struct {
  ElemType data[MaxSize]; // 数组存储元素
  int length;             // 存储当前线性表的长度
} SqList;
// #endregion define

// #region InitList
void InitList(SqList *L) {
  // malloc 尝试申请内存，假设它不会失败
  L = (SqList *)malloc(sizeof(SqList));
  // ...做些其他的初始化操作!
  L->length = 0;
}
// #endregion InitList

// #region DestroyList
void DestroyList(SqList *L) {
  // 尝试释放内存，假设它不会失败
  free(L);
}
// #endregion DestroyList

// #region ListEmpty
int ListEmpty(SqList *L) { return L->length == 0; }
// #endregion ListEmpty

// #region ListLength
int ListLength(SqList *L) { return L->length; }
// #endregion ListLength

// #region DispList
void DispList(SqList *L) {
  if (ListEmpty(L))
    return;

  for (int i = 0; i < L->length; i++)
    printf("%c", L->data[i]);
  printf("\n");
}
// #endregion DispList

// #region GetElem
int GetElem(SqList *L, int i, ElemType *e) {
  if (i < 1 || i > L->length)
    return 0;
  *e = L->data[i - 1];
  return 1;
}
// #endregion GetElem

// #region LocateElem
int LocateElem(SqList *L, ElemType e) {
  for (int i = 0; i < L->length; i++)
    if (L->data[i] == e)
      return i + 1;
  return 0;
}
// #endregion LocateElem

// #region ListInsert
int ListInsert(SqList *L, int i, ElemType e) {
  if (i < 1 || i > L->length + 1)
    return 0;
  if (L->length >= MaxSize)
    return 0;
  for (int j = L->length; j >= i; j--)
    L->data[j] = L->data[j - 1];
  L->data[i - 1] = e;
  L->length++;
  return 1;
}
// #endregion ListInsert

// #region ListDelete
int ListDelete(SqList *L, int i, ElemType *e) {
  if (i < 1 || i > L->length)
    return 0;
  *e = L->data[i - 1];
  for (int j = i; j < L->length; j++)
    L->data[j - 1] = L->data[j];
  L->length--;
  return 1;
}
// #endregion ListDelete

// #region ListMerge
int ListMerge(SqList *La, SqList *Lb, SqList *Lc) {
  if (La->length + Lb->length > Lc->length) 
    return 0;
  
  int i = 0, j = 0, k = 0;
  while (i < La->length && j < Lb->length) {
    if (La->data[i] <= Lb->data[j]) {
      Lc->data[k] = La->data[i];
      i++;
    } else {
      Lc->data[k] = Lb->data[j];
      j++;
    }
    k++;
  }
  while (i < La->length) {
    Lc->data[k] = La->data[i];
    i++;
    k++;
  }
  while (j < Lb->length) {
    Lc->data[k] = Lb->data[j];
    j++;
    k++;
  }
  Lc->length = k;
  return 1;
}
// #endregion ListMerge
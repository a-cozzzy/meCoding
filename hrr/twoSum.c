/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *res=(int*)malloc(2*sizeof(int));
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                res[0]=i;
                res[1]=j;
                *returnSize=2;
                return res;
            }
        }
    }

    return NULL;
    free(res);
}

int main(){
    int numsSize=4;
    int nums[4]={2,7,11,15};
    int target=9;
    int returnSize[2]={0};

    int res[]= twoSum( nums, numsSize, target,returnSize);
    for(int i=0;i<2;i++){
        printf("%d",res[i]);
    }
}
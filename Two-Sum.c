/*
Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int n = 2;
    int* twoNum = (int *) malloc (n*sizeof(int));
    
    for (int i = 0; i<numsSize; i++){
        for (int j = i+1; j<numsSize; j++){
            if (nums[i] + nums[j] == target){
                twoNum[0] = i;
                twoNum[1] = j;
            }
        }
    }
    return twoNum;
    
}

int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 0) {
        return 0;
    }
    int local = *nums;
    int global = *nums;
    
    nums++;
    
    for(int i=1; i<numsSize; i++) {
        if(*nums > (local + *nums)) {
            local = *nums;
        } else {
            local = local + *nums;
        }
        
        if(local > global) {
            global = local;
        }
        nums++;
    }
    return global;
}
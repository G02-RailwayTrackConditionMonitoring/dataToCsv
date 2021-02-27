
#include <stdio.h>
#include <stdint.h>

#define HALF_INT 32767
#define ACC_RANGE 16 

int main(int argc, char *argv[]){

    FILE* file;
    FILE* csv_file;
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error opening file %s...",argv[1]);
        return -1;
    }
   
    csv_file = fopen(argv[2], "w+");
    if(csv_file == NULL){
        printf("Error opening output file %s...",argv[2]);
        return -1;
    }
    typedef struct{
        
        int16_t x;
        int16_t y;
        int16_t z;
    }reading;

    typedef struct{
        float x;
        float y;
        float z;
    
    }reading_float;

    reading r;
    reading_float rf;
    uint32_t count=0;
    while(fread(&r,2,3,file)){

        printf("n=%d x: %d, y: %d, z:%d\n",count,r.x,r.y,r.z);
        rf.x =((float) r.x)/HALF_INT * ACC_RANGE;
        rf.y = ((float)r.y)/HALF_INT * ACC_RANGE;
        rf.z = ((float)r.z)/HALF_INT * ACC_RANGE;
        char str[100];
        snprintf(str,100,"%f,%f,%f\n",rf.x,rf.y,rf.z);
        fputs(str,csv_file);
        count++;
    }
    fclose(csv_file);
    fclose(file);
    return 0;
}

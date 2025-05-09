#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int x;
    char c;
    scanf("%d",&x);
    getchar();
    scanf("%c",&c);

    printf("%d\t" "%c\n",x,c);


    puts("Hello,World"); // shittier version of printf

    char T[]="Dogs";
    printf("%d\n",strlen(T));


    char test1[]="HEEELLLPPP";
    char test2[]="SSSHHHIIITT";
    //i want test2 to test1
    strcpy(test1,test2);
    printf("%s\n",test1);
    printf("%s\n",test2);

    printf("%d\n",strcmp(test1,test2));


    int *arr = malloc(5 * sizeof(int));  // Allocated, but not initialized
    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(arr + i));  // ⚠️ Garbage values
    }
    free(arr);
    // for int it gives random numbers or adresses within the uninitilized memory
    // for char (%c) it gives empty 
    // for char (%s) it gives segmentation fault


    char *ptr = malloc(3*sizeof(char));
    if (ptr==NULL) return 1;
    for(int i=0;i<3;i++){
        printf(" %c\n",ptr[i]);
    }
    free(ptr);              // it frees the pointer so its doesn't point to nothing and gives the NULL


    char haystack[] = "This is a simple string adddddiiinnngggg";
    char needle[] = "string";
    
    char *result = strstr(haystack, needle);

    if (result != NULL){
    printf("Found substring: '%s'\n", result);  // Output: string adddddiiinnngggg
    printf("%s\n",strstr(haystack,needle));
    }
    else
    printf("Substring not found\n");


    char names[12] = "dog and cat";
    printf("%d",strlen(names)); // strlen does count spaces it outputs 11 (12 - \0 = 11)
    return 0;
}

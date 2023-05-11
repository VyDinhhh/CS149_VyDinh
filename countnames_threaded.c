#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define TABLE_SIZE 100


// Thread
pthread_mutex_t tlock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tlock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tlock3 = PTHREAD_MUTEX_INITIALIZER;


void *thread_runner(void *);
pthread_t tid1, tid2;


struct THREADDATA_STRUCT
{
    pthread_t creator;
};
typedef struct THREADDATA_STRUCT THREADDATA;


THREADDATA *p = NULL;


int logindex = 0;
int *logip = &logindex;


// Hash to count name
typedef struct Node
{
    char name[100];
    int count;
    struct Node *next;
} Node;
Node *hashTable[TABLE_SIZE];


unsigned int hash(const char *name)
{
    unsigned int hashValue = 0;
    while (*name != '\0')
    {
        hashValue = (hashValue << 5) + *name++;
    }
    return hashValue % TABLE_SIZE;
}


Node *createNode(const char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

//add name to hash table
void insertName(Node *hashTable[], const char *name)
{
    unsigned int index = hash(name);


    if (hashTable[index] == NULL)
    {
        hashTable[index] = createNode(name);
    }
    else
    {
        Node *current = hashTable[index];
        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0)
            {
                current->count++;
                return;
            }
            if (current->next == NULL)
            {
                current->next = createNode(name);
                return;
            }
            current = current->next;
        }
    }
}

//print names
void printHashTable(Node *hashTable[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("%s: %d\n", current->name, current->count);
            current = current->next;
        }
    }
}

//free hash
void freeHashTable(Node *hashTable[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *current = hashTable[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}


int hours, minutes, seconds, day, month, year;
time_t now;
struct tm *local;

void printTime(time_t now, struct tm *local)
{
    hours = local->tm_hour;       // get hours since midnight (0-23)
    minutes = local->tm_min;      // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;      // get seconds passed after minute (0-59)
    day = local->tm_mday;         // get day of month (1 to 31)
    month = local->tm_mon + 1;    // get month of year (0 to 11)
    year = local->tm_year + 1900; // get year since 1900
    // print local time
    if (hours < 12) // before midday
        printf(", %02d/%02d/%d %02d:%02d:%02d am: ", day, month, year, hours, minutes, seconds);
    else // after midday
        printf(", %02d/%02d/%d %02d:%02d:%02d pm: ", day, month, year, hours - 12, minutes, seconds);
}


int main(int argc, char *argv[])
{
	//check if there are 2 files
    if (argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }


    // Create threads
    printf("Create first thread\n");
    pthread_create(&tid1, NULL, thread_runner, argv[1]);
    printf("Create second thread\n");
    pthread_create(&tid2, NULL, thread_runner, argv[2]);


    // Wait for threads to complete


    pthread_join(tid1, NULL);
    printf("First thread exited\n");


    pthread_join(tid2, NULL);
    printf("Second thread exited\n");


    // Print the results


    printf("\nName Counts\n");
    printHashTable(hashTable);


    // Free the hash table
    freeHashTable(hashTable);


    return 0;
}


void *thread_runner(void *x)
{
    pthread_t me;
    me = pthread_self();
    time(&now);
    local = localtime(&now);
    // printf("This is thread %ld (p=%p)\n", me, p);
    ++logindex;
    printf("Logindex %d, thread %ld, PID %d", logindex, me, getpid());
    printTime(now, local);
    printf("This is thread %ld and I created THREADDATA %p\n", me, p);
    pthread_mutex_lock(&tlock2); // critical section starts
    if (p == NULL)
    {
        p = (THREADDATA *)malloc(sizeof(THREADDATA));
        p->creator = me;
    }
    pthread_mutex_unlock(&tlock2); // critical section ends


    // Thread 1
    if (p != NULL && p->creator == me)
    {
    	//open file
        char *filename = (char *)x;
        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Failed to open file: %s\n", filename);
            pthread_exit(NULL);
        }
        else
        {
            ++logindex;
            printf("Logindex %d, thread %ld, PID %d", logindex, me, getpid());
            printTime(now, local);
            printf("opened file %s\n", filename);
        }
        int count = 0;
        char line[100];
        // add name to hash
        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (line[0] != '\n')
            {
                line[strcspn(line, "\n")] = '\0'; // Remove newline
                pthread_mutex_lock(&tlock3);
                insertName(hashTable, line);
                pthread_mutex_unlock(&tlock3);
            }
            else
            {
                printf("Warning - file %s line %d is empty\n", filename, count);
            }
            count++;
        }


        fclose(file);
    }
    else
    {
        ++logindex;
        printf("Logindex %d, thread %ld, PID %d", logindex, me, getpid());
        printTime(now, local);
        printf("This is thread %ld and I can access the THREADDATA %p\n", me, p);
    }




    pthread_mutex_lock(&tlock1); // Start of critical section
    if (p != NULL && p->creator == me)
    {
        ++logindex;
        printf("Logindex %d, thread %ld, PID %d", logindex, me, getpid());
        printTime(now, local);
        printf("This is thread %ld and I delete THREADDATA\n", me);
        // Free the THREADDATA object.
        free(p);
        p = NULL;
    }
    else
    {
        ++logindex;
        printf("Logindex %d, thread %ld, PID %d", logindex, me, getpid());
        printTime(now, local);
        printf("This is thread %ld and I can access the THREADDATA\n", me);
    }
    //++(*logip);
    pthread_mutex_unlock(&tlock1); // End of critical section


    pthread_exit(NULL);
}





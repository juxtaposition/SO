#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define PLAT "Platon"
#define NIET "Nietzsche"
#define DESC "Descartes"
#define HEGE "Hegel"
#define ARIS "Aristoteles"

int comida = 6;


struct cutlery{
  int state; // A boolean state, bus or free
};

// Function shared for the adjunt
void goto_xy(int x, int y){
	printf("\033[%d;%df", y, x);
}

// Print with format two strings
void printInfo(char* str1, char* str2) {
	printf("%s %s \n", str1, str2);
}

// Struct for philosophers
struct philosopher {
	struct cutlery* ten1;
	struct cutlery* ten2;
	char *name;
	int cantEat;
} philosopher;

void *eat(void *h1) {
	struct philosopher *f1;
	f1 = (struct philosopher*) h1;
	char *cName = f1->name;
	if(cName == PLAT) 
		goto_xy(1,1);

	printInfo(cName, "is thinking\n");

	while(f1->cantEat > 0) {
	  if(f1->ten1->state == 0 && f1->ten2->state == 0) {
		goto_xy(1,2);
		printInfo(cName, "has hungry\n");
		f1->ten1->state = f1->ten2->state = 1;
		goto_xy(1,3);
		printInfo(cName, "take the cutlery\n");
		while(f1->cantEat > 0) {
		  f1->cantEat--;
		  goto_xy(1,4);
		  printInfo(cName, "is eating\n");
		}
	  } else {
 		printInfo(cName, "can't eat\n");
      }
	}
	f1->ten1->state = f1->ten2->state = 0;
	printInfo(cName, "has finised to eat \n");
	pthread_exit("Thread finished");
}


int main() {
	pthread_t t1, t2, t3, t4, t5; // Threads
	// Reserved the five cutlerys
	struct cutlery *ten1 = (struct cutlery*) malloc(sizeof(struct cutlery));
	struct cutlery *ten2 = (struct cutlery*) malloc(sizeof(struct cutlery));
	struct cutlery *ten3 = (struct cutlery*) malloc(sizeof(struct cutlery));
	struct cutlery *ten4 = (struct cutlery*) malloc(sizeof(struct cutlery));
	struct cutlery *ten5 = (struct cutlery*) malloc(sizeof(struct cutlery));

	// Initialize cutlery states
	ten1->state = ten2->state = ten3->state = ten4->state = ten5->state = 0;
	// Reserved memory for the five filos
	struct philosopher* fil1 = (struct philosopher*) malloc(sizeof(struct philosopher));
	struct philosopher* fil2 = (struct philosopher*) malloc(sizeof(struct philosopher));
	struct philosopher* fil3 = (struct philosopher*) malloc(sizeof(struct philosopher));
	struct philosopher* fil4 = (struct philosopher*) malloc(sizeof(struct philosopher));
	struct philosopher* fil5 = (struct philosopher*) malloc(sizeof(struct philosopher));

	fil1->name = PLAT;
	fil1->cantEat = comida;
	fil1->ten1 = ten1;
	fil1->ten2 = ten2;

	fil2->name = DESC;
	fil2->cantEat = comida;
	fil2->ten1 = ten2;
	fil2->ten2 = ten3;

	fil3->name = NIET;
	fil3->cantEat = comida;
	fil3->ten1 = ten3;
	fil3->ten2 = ten4;

	fil4->name = HEGE;
	fil4->cantEat = comida;
	fil4->ten1 = ten4;
	fil4->ten2 = ten5;

	fil5->name = ARIS;
	fil5->cantEat = comida;
	fil5->ten1 = ten5;
	fil5->ten2 = ten1;

if(pthread_create( &t1, NULL, eat, (void*) fil1) != 0) {
	perror("pthread_create() error");
	exit(1);
}

if(pthread_create( &t2, NULL, eat, (void*) fil2) != 0) {
	perror("pthread_create() error");
	exit(1);
}

if(pthread_create( &t3, NULL, eat, (void*) fil3) != 0) {
	perror("pthread_create() error");
	exit(1);
}

if(pthread_create( &t4, NULL, eat, (void*) fil4) != 0) {
	perror("pthread_create() error");
	exit(1);
}

if(pthread_create( &t5, NULL, eat, (void*) fil5) != 0) {
	perror("pthread_create() error");
	exit(1);
}


if (pthread_join(t1, NULL) != 0) {
  perror("pthread_join() error");
  exit(2);
}

if (pthread_join(t2, NULL) != 0) {
  perror("pthread_join() error");
  exit(2);
}

if (pthread_join(t3, NULL) != 0) {
  perror("pthread_join() error");
  exit(2);
}

if (pthread_join(t4, NULL) != 0) {
  perror("pthread_join() error");
  exit(2);
}

if (pthread_join(t5, NULL) != 0) {
  perror("pthread_join() error");
  exit(2);
}

return 0;
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int comida = 6;

struct cutlery{
	int state; // A boolean state, bus or free
};

void printInfo(char* str1, char* str2) {
	printf("%s %s \n", str1, str2);
}

struct philosopher {
	struct cutlery* ten1;
	struct cutlery* ten2;
	char *name;
	int cantEat;
} philosopher;

void *eat(void *h1) {
	struct philosopher *f1;
	f1 = (struct philosopher*) h1;
	printInfo(f1->name, "is thinking");

	while(f1->cantEat > 0) {
	  if(f1->ten1->state == 0 && f1->ten2->state == 0) {
		printInfo(f1->name, "has hungry");
		f1->ten1->state = f1->ten2->state = 1;
		printInfo(f1->name, "take the cutlery");
		while(f1->cantEat > 0) {
		  f1->cantEat--;
		  printInfo(f1->name, "is eating");
		}
	  } else {
 		printInfo(f1->name, "can't eat");
      }
	}
	f1->ten1->state = f1->ten2->state = 0;
	printInfo(f1->name, "has finised to eat \n");
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

	fil1->name = "Platon";
	fil1->cantEat = comida;
	fil1->ten1 = ten1;
	fil1->ten2 = ten2;

	fil2->name = "Descartes";
	fil2->cantEat = comida;
	fil2->ten1 = ten2;
	fil2->ten2 = ten3;

	fil3->name = "Nietsche";
	fil3->cantEat = comida;
	fil3->ten1 = ten3;
	fil3->ten2 = ten4;

	fil4->name = "Hegel";
	fil4->cantEat = comida;
	fil4->ten1 = ten4;
	fil4->ten2 = ten5;

	fil5->name = "Aristoteles";
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

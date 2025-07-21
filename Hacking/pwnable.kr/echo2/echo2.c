#include <stdio.h>
#include <stdlib.h>

struct formalities{
	char name[24];
	void (*greeting)(char *);
	void (*farewell)(char *);
};

struct formalities *o;
char id[4];
void (*func[3])(void);

void get_input(char *buf, int size){
	fgets(buf, size, stdin);
}

void greetings(char *name){
	printf("hello %s\n", name);
}

void byebye(char *name){
	printf("goodbye %s\n", name);
}

void echo1(){
	puts("not supported");
}

void echo2(){
	char buff[32];
	o->greeting(o->name);
	get_input(buff, 32);
	printf(buff); // format string vulnerability
	o->farewell(o->name);
}

void echo3(){
	char *ptr;
	o->greeting(o->name);
	ptr = malloc(32);
	get_input(ptr, 32);
	puts(ptr);
	free(ptr);
	o->farewell(o->name);
}

void cleanup(){
	free(o);
}



int main(){
	char buff[25];
	unsigned int answer;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IOLBF, 0);

	o = malloc(0x28); // or malloc(sizeof(struct formalities))
	o->greeting = greetings;
	o->farewell = byebye;

	printf("hey, what's your name? : ");
	scanf("%24s", buff);
    o->name[0] = buff[0]; o->name[1] = buff[1]; o->name[2] = buff[2]; o->name[3] = buff[3]; o->name[4] = buff[4]; o->name[5] = buff[5]; o->name[6] = buff[6]; o->name[7] = buff[7];
	o->name[8] = buff[8]; o->name[9] = buff[9]; o->name[10] = buff[10]; o->name[11] = buff[11]; o->name[12] = buff[12]; o->name[13] = buff[13]; o->name[14] = buff[14]; o->name[15] = buff[15];
	o->name[16] = buff[16]; o->name[17] = buff[17]; o->name[18] = buff[18]; o->name[19] = buff[19]; o->name[20] = buff[20]; o->name[21] = buff[21]; o->name[22] = buff[22]; o->name[23] = buff[23];
    id[0] = buff[0]; id[1] = buff[1]; id[2] = buff[2]; id[3] = buff[3];
	getchar();

	func[0] = echo1;
	func[1] = echo2;
	func[2] = echo3;
	answer = 0;

	while (1){
		puts("\n- select echo type -");
		puts("- 1 : BOF echo");
		puts("- 2 : FSB echo");
		puts("- 3 : UAF echo");
		puts("- 4 : exit");
		printf("> ");
	
		scanf("%d", &answer);
		getchar();

		if (answer < 4){
			func[answer - 1]();
		}
		else if (answer != 4){
			puts("invalid menu");
		}
		else{
			cleanup();
			printf("Are you sure you want to exit? (y/n) ");
			answer = getchar();
			if (answer != 'y'){
				continue;
			}
			break;
		}
	}
	
	
	
}
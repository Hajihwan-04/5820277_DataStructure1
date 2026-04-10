#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct studentInfo {
	char name[25];
	int stuNum;
	int score;
};

int main() {
	int N;
	printf("학생 수 입력 : ");
	scanf_s("%d", &N);

	if (N <= 0) {
		printf("!!ERROR!!\n0이하의 수 불가.");
		return 1;
	}

	struct studentInfo* studentList = (struct studentInfo*)malloc(sizeof(struct studentInfo) * N);
	if (studentList == NULL) {
		printf("No more memory");
		free(studentList);
		return 1;
	}

	FILE* fp;
	fp = fopen("C:\\Users\\하지환\\Desktop\\계명대학교\\2026-1\\자료구조\\프로그램\\5820277_DataStructure1\\Assignment\\2026.04.07\\name_list.txt", "r");
	if (fp == NULL) {
		printf("Fail to open\n");
		return 0;
	}
	char file_buff[25];
	int high = 0, low = 101, highStu = 0, lowStu = 0, count = 0;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < N && fgets(file_buff, sizeof(file_buff), fp) != NULL; i++) {
		(*(studentList + i)).stuNum = i;
		strcpy((*(studentList + i)).name, file_buff);
		(*(studentList + i)).score = (rand() % 100) + 1;
		memset(file_buff, 0, sizeof(file_buff));
		if ((*(studentList + i)).score < low) {
			low = (*(studentList + i)).score;
			lowStu = i;
		}
		if ((*(studentList + i)).score > high) {
			high = (*(studentList + i)).score;
			highStu = i;
		}
		avg += (*(studentList + i)).score;
		count++;
	}
	fclose(fp);

	avg /= count;
	if (count != N) printf("학생 자료 부족\n");
	printf("학생 수 : %d\n", count);
	printf("\n최저점 학생 정보\n 이름: %s 학번: %d\n 성적: %d\n", (*(studentList + lowStu)).name, (*(studentList + lowStu)).stuNum, (*(studentList + lowStu)).score);
	printf("\n최고점 학생 정보\n 이름: %s 학번: %d\n 성적: %d\n", (*(studentList + highStu)).name, (*(studentList + highStu)).stuNum, (*(studentList + highStu)).score);
	printf("\n평균 점수 : %.2f\n", avg);

	free(studentList);
	return 0;
}
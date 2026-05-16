#include "LinkedList.h"

PointType getItem() {
	printf("정수 2개를 입력하세요 ex) \"10 20\" : ");
	int a, b;
	scanf_s("%d %d", &a, &b);
	PointType result;
	result.x = a;
	result.y = b;
	result.next = 0;
	return result;
}

int main() {
	struct linkedList* myList1;
	myList1 = createLinkedList();

	int end = 0;
	while (end == 0) {
		printf("메뉴 : \n1. 맨 앞에 추가: 정수를 입력받아 리스트의 가장 앞에 삽입\n");
		printf("2. 맨 뒤에 추가 : 정수를 입력받아 리스트의 가장 뒤에 삽입\n");
		printf("3. 특정 위치에 추가 : 위치(index)와 정수를 입력받아 해당 위치에 삽입\n");
		printf("4. 특정 위치 삭제 : 위치(index)를 입력받아 해당 노드를 삭제하고 값 출력\n");
		printf("5. 전체 목록 출력 : 현재 리스트에 저장된 모든 정수를 순서대로 출력\n");
		printf("6. 리스트 크기 확인 : 현재 저장된 노드의 총 개수를 출력\n");
		printf("0. 종료 : 모든 메모리를 해제(destroy)하고 프로그램을 종료\n입력 : ");
		int input;
		scanf_s("%d", &input);
		PointType newItem;
		switch (input) {
		case 1:
			newItem = getItem();
			insertFirstLinkedList(myList1, newItem);
			break;
		case 2:
			newItem = getItem();
			insertLastLinkedList(myList1, newItem);
			break;
		case 3:
			printf("원하는 리스트의 위치를 입력하세요 : ");
			int pos1;
			scanf_s("%d", &pos1);
			newItem = getItem();
			insertAtLinkedList(myList1, pos1, newItem);
			break;
		case 4:
			printf("원하는 리스트의 위치를 입력하세요 : ");
			int pos2;
			scanf_s("%d", &pos2);
			deleteAtLinkedList(myList1, pos2);
			break;
		case 5:
			printLinkedList(myList1);
			break;
		case 6:
			printf("리스트의 총 노드 갯수 : %d\n\n", sizeLinkedList(myList1));
			break;
		case 0:
			destroyLinkedList(myList1);
			end = 1;
			printf("종료되었습니다.\n");
			break;
		default :
			printf("잘못 입력하였습니다.\n\n");
		}
	}

	return 0;
}
# queue
c를 이용해 FIFO형태의 자료구조 queue를 구현

## new_queue();
새로운 큐를 생성한다.
해당 큐에는 큐의 시작과 끝을 알 수 있는 head와 tail이 들어있다.
head와 tail은 단순이 위치를 표시하기 위한 것으로 쓰레기 값을 가지고 있다.

## new_list(int value);
새로운 리스트를 생성한다.
여기서 리스트는 큐가 가지고 있는 데이터 형식이다.
이전 리스트의 주소, 다음 리스트의 주소, int 값을 가진다.
malloc으로 생성하므로 사용후 반드시 free해 주어야 한다.

## push_queue(t_queue queue, t_list *new);
큐에 새로운 리스트를 삽입한다.
삽입된 리스트는 큐의 맨 끝에 위치한다.

head -> old_list1 -> old_list2 -> new_list -> tail

## pop_queue(t_queue queue);
큐에서 제일 처음 들어온 값을 빼내 반환한다.

기존 큐  : head -> old_list1 -> old_list2 -> new_list -> tail

함수 실행 후
큐      :head -> old_list2 -> new_list -> tail
반환값   : old_list1

## print_queue(t_queue queue);
큐 안에 든 모든 값을 출력한다.
먼저 들어온 숫자를 먼저 출력한다.

## free_queue(t_queue queue);
큐에 들어있는 리스트들을 모두 free 시킨다.
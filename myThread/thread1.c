// pthread.h需要手动链接 -l pthread
// 多线程实现 0 - 400 顺序输出

#include <pthread.h>
#include <stdio.h>
#include <string.h> // for memset()

static int cnt = 0;

pthread_mutex_t mutex;

static void*
thr1(void *arg)
{
	//pthread_detach(pthread_self());
	for(int i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mutex);
		printf("thread num = %lu, cnt = %d\n", pthread_self(), cnt);
		int cnttmp = cnt;
		cnttmp++;
		cnt = cnttmp;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	int arg = 0;

	const int N_thread = 4;
	pthread_t tids[N_thread];
	memset(tids, 0, sizeof(tids));
	pthread_mutex_init(&mutex, NULL);

	for(int i = 0; i < N_thread; i++)
	{
		// ptr->tid; t_attr; t_func; t_func_arg;
		pthread_create(&tids[i], NULL, thr1, (void *)&arg);
		printf("i = %d begin\n", i);
		//fflush(stdout);
	}
	
	for(int i = 0; i < N_thread; i++)
	{
		pthread_join(tids[i], NULL);
	}

	return 0;
}

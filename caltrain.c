#include <pthread.h>
#include "caltrain.h"



void
station_init(struct station *station)
{
    pthread_mutex_init(&station->lock_mutex,NULL);
    pthread_cond_init(&station->trainleft,NULL);
    pthread_cond_init(&station->trainarrive,NULL);
    station->boardpass=0;
    station->waitpass=0;
}

void
station_load_train(struct station *station, int count)
{
    pthread_mutex_lock(&station->lock_mutex);
    station->empty=count;
    while(station->empty>0 &&station->waitpass>0){
        pthread_cond_broadcast(&station->trainarrive);
        pthread_cond_wait(&station->trainleft,&station->lock_mutex);
    }
    station->empty=0;
    pthread_mutex_unlock(&station->lock_mutex);
}

void
station_wait_for_train(struct station *station)
{
    pthread_mutex_lock(&station->lock_mutex);
    station->waitpass++;
    while(station->boardpass==station->empty) pthread_cond_wait(&station->trainarrive,&station->lock_mutex);
    station->waitpass--;
    station->boardpass++;
    pthread_mutex_unlock(&station->lock_mutex);
}

void
station_on_board(struct station *station)
{
    pthread_mutex_lock(&station->lock_mutex);
    station->empty--;
    station->boardpass--;
    if((station->waitpass==0 &&station->boardpass==0)||station->empty==0){
        station->boardpass=0;
        pthread_cond_signal(&station->trainleft);
    }
    pthread_mutex_unlock(&station->lock_mutex);
}
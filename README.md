# Caltrain-synchronization
## 1.Problem Statement:
1. CalTrain (the train running in California, USA) has decided to improve its efficiency by automating not just its trains but also its passengers. From now on, passengers will be robots. Each robot and each train is controlled by a thread. You have been hired to write synchronization functions that will guarantee orderly loading of trains. You must define a structure struct station, plus several functions described below.

2. When a train arrives in the station and has opened its doors, it invokes the function: station_load_train(struct station * station, int count) where count indicates how many seats are available on the train. The function must not return until the train is satisfactorily loaded (all passengers are in their seats, and either the train is full or all waiting passengers have boarded). Note, that the train must leave the station promptly if no passengers are waiting at the station or it has no available free seats.

3. When a passenger robot arrives in a station, it first invokes the function: station_wait_for_train(struct station * station) This function must not return until a train is in the station (i.e., a call to station load train is in progress) and there are enough free seats on the train for this passenger to sit down. Once this function returns, the passenger robot will move the passenger on board the train and into a seat (you do not need to worry about how this mechanism works).

# 2. How to Run the code:
1. download source code either as Zip file or clone it.
2. open Terminal and run the following command:
  - $make
  - $chmod +x repeat.sh
  - $./repeat.sh
3- After running the previous command lines an output file will be produced.
### Note:
- Your laptop should be using Ubuntu either installed or on top of Virtual Machine (VM).
- If you’re using VM, make sure you’ve allocated more than 1 core for the VM.

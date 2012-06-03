#include <vector>
#include <algorithm>


// A compact struct to hold the value and its list index
template <typename T, typename ClientData> struct elementIndex {
   T value;
   int arrayIndex; // Denotes which array or vector or list the data came from
   int position;   // Denotes the current index in the array
   ClientData metaData;   // Can be used by clients/callers to set their own context data

   elementIndex(): value(), metaData()
   {
      arrayIndex = -1;
      position = -1;
   }

   elementIndex(T data, int vIndex, int curPos, ClientData clientData)
   {
      value = data;
      arrayIndex = vIndex;
      position = curPos;
      metaData = clientData;
   }

   bool isValidElement()
   {
      return arrayIndex >= 0;
   }
};

//   Functionality:
//      Merge K sorted arrays using TOURNAMENT TREE
//
//   Input:
//      vector <vector<int>>& sortedArrays - K sorted arrays
//   Output:
//      vector <vector<int>>& sortedArrays - One array which is result of merging K sorted arrays
//

void mergeSortedArraysUsingTournamentTree(vector <vector<int>>& sortedArrays)
{
   if (sortedArrays.size() == 0) {
      return;
   }

   removeEmptyVectors<int>(sortedArrays);

   vector<int> mergedSortedArray;
   vector<elementIndex<int, int>> tournamentTree;
   int firstLeaf = 0, vIndex = 0, numOfPlayers = sortedArrays.size();

   buildTournamentTree(tournamentTree, firstLeaf, sortedArrays);
   playTournament(tournamentTree, firstLeaf);

   while (numOfPlayers) {
      int vIndex = tournamentTree[0].arrayIndex, curPos = -1, value;
      elementIndex<int, int> tournamentWinner = tournamentTree[0];

      //   1) Get winner and add that to output array
      mergedSortedArray.push_back(tournamentWinner.value);
      //   2) Fetch next data
      curPos = tournamentWinner.position;
      if (fetchNextData(sortedArrays[vIndex], curPos, value)) {
         elementIndex<int, int> newPlayer(value, vIndex, curPos, tournamentWinner.metaData);
         // Add this new player at the position of the last Game's winner
         addPlayerAt(tournamentTree, newPlayer);
      }
      else { // If no more elements in the current vector then make this player an automatic loser
         --numOfPlayers;
         tournamentTree[tournamentWinner.metaData].arrayIndex = -1;
         elementIndex<int, int> newPlayer(value, -1, -1, tournamentWinner.metaData);
         addPlayerAt(tournamentTree, newPlayer);
      }
   }

   sortedArrays.clear();
   sortedArrays.push_back(mergedSortedArray);
}


// Functionality:
//   Creates a tournament tree. Internal representation is using array/vector.
//   Represents the complete binary tree using array.
//
//   Input:
//      vector<elementIndex<int, int>>& tournamentTree - Tournament tree to be populated
//      int& firstLeaf   - Index of the first player in the last level
//      const vector<vector<int>>& sortedArrays - vector of sorted arrays
//

void buildTournamentTree(vector<elementIndex<int, int>>& tournamentTree, int& firstLeaf, const vector<vector<int>>& sortedArrays)
{
   if (sortedArrays.size() == 0) {
      return;
   }

   int size = 1, tournamentTreeSize = 0, vIndex = 0;

   while (size < sortedArrays.size()) {
      size*=2;
   }

   firstLeaf = size - 1;
   tournamentTreeSize = (2 * size) - 1;
   tournamentTree.resize(tournamentTreeSize);

   for (int i = firstLeaf; vIndex < sortedArrays.size(); i++) {
      tournamentTree[i].value = sortedArrays[vIndex].at(0);
      tournamentTree[i].arrayIndex = vIndex;
      tournamentTree[i].position = 1;
      tournamentTree[i].metaData = i;
      ++vIndex;
   }
}


//   Functionality:
//      Assumption:
//         The given tournament tree is expected to be the complete binary tree
//   Given a Tournament tree and the index of the first player, conducts a tournament
//   A match is played against a pair of players and the winner is promoted to the next level.
//   Input:
//      vector<elementIndex<int, int>>& tournamentTree - Tournament tree containing players information
//      int firstLeaf                           - Index of the first player in the leaf level of the complete Binary tree
//
//   Output:
//      void

void playTournament(vector<elementIndex<int, int>>& tournamentTree, int firstLeaf)
{
   int thisLevelLeftMostPlayer = firstLeaf;

   while (thisLevelLeftMostPlayer > 0) {
      int left = thisLevelLeftMostPlayer, thisLevelRigthMostPlayer = 0, winner = -1, parent = 0;
      thisLevelRigthMostPlayer = 2 * left;

      while (left < thisLevelRigthMostPlayer) {
         winner = playMatch(tournamentTree[left], tournamentTree[left+1]);
         if (winner <= 0) {
            break;
         }
         parent = left/2;
         tournamentTree[parent] = tournamentTree[winner];
         left+=2;
      }
      thisLevelLeftMostPlayer = (thisLevelLeftMostPlayer - 1)/2;
   }

}


//   Functionality:
//      Assumption:
//         The given tournament tree is expected to be the complete binary tree
//
//      Given a tournament tree, insert a new player at certain position (indicated by newPlayer.metaData)
//      and play the tournament with the rest of the players
//      This will promote the winner to the next level along the path till it reaches the root
//      At the most log n matches (considering there are n players)
//
//      Input:
//         vector<elementIndex<int, int>>& tournamentTree - Tournament tree with players information
//         const elementIndex<int, int>& newPlayer        - New player information

void addPlayerAt(vector<elementIndex<int, int>>& tournamentTree, const elementIndex<int, int>& newPlayer)
{
   if(tournamentTree.size() == 0) {
      return;
   }

   int playerPosition = newPlayer.metaData;

   tournamentTree[newPlayer.metaData] = newPlayer;
   while (playerPosition > 0) {
      int player1, player2, winner, parent;
      player1 = (playerPosition % 2 ? playerPosition : playerPosition - 1);
      player2 = player1 + 1;
      parent = player1/2;
      winner = playMatch(tournamentTree[player1], tournamentTree[player2]);
      tournamentTree[parent] = ((winner != -1) ? tournamentTree[winner] : tournamentTree[player1]);
      playerPosition = parent;
   }

}



// Functionality:
//   Given two player's meta data, finds the winner
//
//   Input:
//      elementIndex& player1 - Player 1's data
//      elementIndex& player2 - Player 2's data
//   Output:
//      Player (array) index in the tournament tree who is the Winner
//   Caution:
//      If both the players are Automatic losers, then the player index will be returned as negative value
//      Callers should check the return value before directly accessing the tournament tree using this player index

int playMatch(const elementIndex<int, int>& player1, const elementIndex<int, int>& player2)
{
   if ((player1.arrayIndex >= 0) && (player2.arrayIndex >= 0)) {
      return player1.value < player2.value ? player1.metaData : player2.metaData;
   }
   else if (player1.arrayIndex < 0) {
      return player2.metaData;
   }

   return player1.metaData;
}


void testTournamentTreeMethod()
{
   vector<int> v;
   int i = 0, count = 5;
   vector <vector<int>> vectorOfSortedArrays;

   srand((unsigned)time(NULL));
   for (; i < 25; i++, count+=15) {
      populateSortedVector(v, count);
      vectorOfSortedArrays.push_back(v);
   }

   mergeSortedArraysUsingTournamentTree(vectorOfSortedArrays);
   if (is_sorted(vectorOfSortedArrays[0])) {
      cout<<"K Sorted Arrays are successfully merged using TOURNAMENT TREE mehtod, complexity is NLOGK"<<endl;
   }
}

#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "mazesolver.h"
#include "mazedisplay.h"
#include "visitedtracker.h"
#include <QMessageBox>
#include <queue>
#include <stack>
#include <vector>


using namespace std;
/*
 * I didn't want the students to have to deal
 * with function pointers, so I'm making the
 * MazeSolver an object with various solve
 * methods.
 *
 * I won't be offended if anyone wants to refactor
 * this to make specific functions for them to call.
 */


class MazeDisplay;
class Maze;

class MazeSolver
{
public:
    MazeSolver(Maze * m, MazeDisplay * md);

    void solveByBFS();

    void solveByDFSIterative();

    void solveByDFSRecursive();

    void solveByAStar(int heuristicChoice);

    void DFSRecursiveHelper(int r, int c, int numExplored, vector<Direction>& parent, VisitedTracker& vt, stack<Direction>& st);

    void setMaze(Maze* m) { maze = m; }

private:

    int squareNumber(int r, int c) const;

    Maze * maze;
    MazeDisplay * display;
    bool stuff;
};

#endif // MAZESOLVER_H
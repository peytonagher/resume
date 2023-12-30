"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]


def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    stack = util.Stack()
    start_state = problem.getStartState()
    stack.push((start_state, []))

    explored = set()

    while not stack.isEmpty():
        current_state, actions = stack.pop()

        if problem.isGoalState(current_state):
            return actions

        if current_state not in explored:
            explored.add(current_state)

            successors = problem.getSuccessors(current_state)
            for successor, action, x in successors:
                if successor not in explored:
                    new_actions = actions + [action]
                    stack.push((successor, new_actions))
    return []


def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    startState = problem.getStartState()
    fringe = util.Queue()
    visited = []

    fringe.push((startState, [], 0))

    while fringe:
        current_state, actions, costs = fringe.pop()

        if not current_state in visited:
            visited.append(current_state)

            if problem.isGoalState(current_state):
                return actions

            for state, action, cost in problem.getSuccessors(current_state):
                if not state in visited:
                    fringe.push((state, actions + [action], cost))
    return []


def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    start_state = problem.getStartState()
    frontier = util.PriorityQueue()
    frontier.push([(start_state, "Stop", 0)], 0)

    explored = {}

    while frontier:
        path = frontier.pop() 
        current_state, x, current_cost = path[-1]  

        if problem.isGoalState(current_state):
            return [action for (x, action, x) in path][1:]

        if current_state not in explored or current_cost < explored[current_state]:
            explored[current_state] = current_cost

            for successor, action, step_cost in problem.getSuccessors(current_state):
                if successor not in explored or current_cost + step_cost < explored[successor]:
                    new_path = list(path)
                    new_path.append((successor, action, current_cost + step_cost))
                    frontier.push(new_path, current_cost + step_cost)
    return []


def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0


def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    start_state = problem.getStartState()
    frontier = util.PriorityQueue()
    frontier.push([(start_state, "Stop", 0)], 0)

    explored = {}

    while frontier:
        path = frontier.pop()
        current_state, x, current_cost = path[-1]

        if problem.isGoalState(current_state):
            return [action for (x, action, x) in path][1:]

        if current_state not in explored or current_cost < explored[current_state]:
            explored[current_state] = current_cost

            for successor, action, step_cost in problem.getSuccessors(current_state):
                if successor not in explored or current_cost + step_cost < explored[successor]:
                    new_path = list(path)
                    new_path.append((successor, action, current_cost + step_cost))
                    total_cost = current_cost + step_cost + heuristic(successor, problem)
                    frontier.push(new_path, total_cost)
    return []




# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        directions = [
        (-1, 0),  # up
        (1, 0),   # down
        (0, -1),  # left
        (0, 1)    # right
        ]

        rowCount = len(grid)
        colCount = len(grid[0])

        def dfs(i, j):
            if i < 0 or i >= rowCount or j < 0 or j >= colCount:
                return

            if grid[i][j] != '1':
                return
            
            grid[i][j] = '2'

            for d in directions:
                x, y = d
                dfs(i + x, j + y)


        numIslands = 0

        for i in range(rowCount):
            for j in range(colCount):
                if grid[i][j] == '1':
                    numIslands += 1
                    dfs(i, j)

        return numIslands




        
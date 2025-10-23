import pygame
import random

# Constants
WIDTH, HEIGHT, CELL_SIZE = 600, 600, 66
GRID_SIZE = 9

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BLUE = (0, 153, 255)
GREEN = (0, 255, 0)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Sudoku Game')

# Function to draw the Sudoku grid
def draw_grid(grid):
    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            rect = pygame.Rect(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE)
            if grid[i][j] != 0:
                text = font.render(str(grid[i][j]), True, BLACK)
                screen.blit(text, (j * CELL_SIZE + 25, i * CELL_SIZE + 25))
            pygame.draw.rect(screen, WHITE, rect, 1)

# Generate a random Sudoku puzzle (very basic implementation)
def generate_sudoku():
    base = 3
    full_board = [[0 for _ in range(GRID_SIZE)] for _ in range(GRID_SIZE)]

    for i in range(GRID_SIZE):
        for j in range(GRID_SIZE):
            num = random.randint(1, 9)
            while num in full_board[i] or any(full_board[x][j] == num for x in range(GRID_SIZE)
                                               if x != i):
                num = random.randint(1, 9)
            full_board[i][j] = num

    # Removing numbers to create a puzzle
    holes = 40  # Number of cells to remove
    for _ in range(holes):
        row, col = random.randint(0, GRID_SIZE - 1), random.randint(0, GRID_SIZE - 1)
        full_board[row][col] = 0

    return full_board

# Main loop
grid = generate_sudoku()
font = pygame.font.Font(None, 40)

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(BLACK)
    draw_grid(grid)
    pygame.display.flip()

pygame.quit()

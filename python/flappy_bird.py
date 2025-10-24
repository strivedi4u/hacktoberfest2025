from random import randrange, choice
from turtle import *
from freegames import vector

bird = vector(0, 0)
balls = []
score = 0
game_over = False

colors = ['#FF6B6B', '#FFD93D', '#6BCB77', '#4D96FF', '#8338EC']

def tap(x, y):
    if not game_over:
        up = vector(0, 30)
        bird.move(up)

def inside(point):
    return -200 < point.x < 200 and -200 < point.y < 200

def draw(alive):
    global score
    clear()

    # Draw background gradient sky
    bgcolor('#87CEEB')
    penup()
    goto(-210, -200)
    color('#87CEEB')
    begin_fill()
    for _ in range(2):
        forward(420)
        left(90)
        forward(420)
        left(90)
    end_fill()

    # Draw bird
    goto(bird.x, bird.y)
    color('black', '#F9C74F' if alive else '#FF6B6B')
    begin_fill()
    circle(10)
    end_fill()

    # Draw balls (obstacles)
    for ball in balls:
        goto(ball.x, ball.y)
        color(choice(colors))
        begin_fill()
        circle(20)
        end_fill()

    # Display Score
    goto(-190, 170)
    color('black')
    write(f"Score: {score}", font=("Arial", 16, "bold"))

    if not alive:
        goto(-80, 0)
        color('#FF0000')
        write("GAME OVER", font=("Courier", 20, "bold"))

    update()

def move():
    global score, game_over
    if game_over:
        return

    bird.y -= 5

    for ball in balls:
        ball.x -= 5

    if randrange(10) == 0:
        y = randrange(-199, 199)
        ball = vector(199, y)
        balls.append(ball)

    while len(balls) > 0 and not inside(balls[0]):
        balls.pop(0)
        score += 1

    if not inside(bird):
        draw(False)
        game_over = True
        return

    for ball in balls:
        if abs(ball - bird) < 15:
            draw(False)
            game_over = True
            return

    draw(True)
    ontimer(move, 50)

setup(420, 420, 370, 0)
hideturtle()
up()
tracer(False)
onscreenclick(tap)
move()
done()

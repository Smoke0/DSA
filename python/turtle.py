import tkinter
import turtle

ben=turtle.Turtle()

ben.pencolor('red')

for i in range(50):
    ben.forward(i*i+50)
    ben.left(90)

ben.pencolor('blue')

for i in range(50):
    ben.forward(i*i+50)
    ben.left(60)
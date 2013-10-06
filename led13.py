# from pyfirmata import Arduino, util
# board = Arduino('/dev/tty.usbserial-A601EGIN')
# board.digital[13].write(1)

from BreakfastSerial import Arduino, Motor
from time import sleep

board = Arduino()
motor = Motor(board, "10")

motor.start(80)
sleep(2)
motor.speed = 160
sleep(2)
# servo.move(200)
# sleep(2)
# servo.move(-200)
# sleep(2)
# servo.move(100)
# sleep(2)
motor.stop()
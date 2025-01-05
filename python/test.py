import keyboard
import mouse
import random
import time

ITEM_COUNT: int = 69
CENTER: tuple[int, int] = (685, 440)
SCROLL: tuple[int, int] = (1530, 855)
ITEMS: dict[int, tuple[int, int]] = {i: (1300 + 75 * ((i - 1) % 3), 15 + 35 * ((i - 1) // 3)) for i in range(1, ITEM_COUNT + 1)}
i: int = 0

time.sleep(2)

while True:
    if keyboard.is_pressed('q'):
        break

    if i == 100:
        mouse.move(*SCROLL)
        mouse.press()
        time.sleep(1)
        mouse.release()
        mouse.move(1200, 850)
        mouse.click()
        i = 0

    mouse.drag(*ITEMS[random.randint(1, ITEM_COUNT)], *CENTER, duration=0.5)
    i += 1

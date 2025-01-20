from PIL import Image
from mss.screenshot import ScreenShot
from mss import mss
from keyboard import send
from time import sleep, perf_counter
from random import choice

toggle_half_life: bool = True
toggle_skill: bool = True

life_cooldown_threshold: float = 0.5
mana_cooldown_threshold: float = 0.5
half_life_cooldown_threshold: float = 6
skill_cooldown_threshold: float = 7.4

life_cords: tuple[int, int] = (150, 1050)
mana_cords: tuple[int, int] = (1800, 1060)
half_life_cords: tuple[int, int] = (125, 975)

life_colour: tuple[int, int, int] = (61, 22, 20)
mana_colour: tuple[int, int, int] = (19, 28, 55)
half_life_colour: tuple[int, int, int] = (138, 25, 28)

life_keys: tuple[str, str] = ('1', '4')
mana_keys: tuple[str, str] = ('2', '5')
half_life_key: str = '3'
skill_key: str = 'A'


def get_screenshot_pixel_colour(region: tuple[int, int]) -> float | tuple[int, ...] | None:
    with mss() as sct:
        screenshot: ScreenShot = sct.grab({"top": region[1], "left": region[0], "width": 1, "height": 1})
        img: Image.Image = Image.frombytes("RGB", screenshot.size, screenshot.bgra, "raw", "BGRX")
        return img.getpixel((0, 0))


def main() -> None:
    sleep(2)
    life_cooldown: float = 0
    mana_cooldown: float = 0
    half_life_cooldown: float = 0
    skill_cooldown: float = 0

    while True:
        if life_colour != get_screenshot_pixel_colour(life_cords):
            if not life_cooldown or perf_counter() - life_cooldown >= life_cooldown_threshold:
                send(choice(life_keys))
                life_cooldown = perf_counter()

        if mana_colour != get_screenshot_pixel_colour(mana_cords):
            if not mana_cooldown or perf_counter() - mana_cooldown >= mana_cooldown_threshold:
                send(choice(mana_keys))
                mana_cooldown = perf_counter()

        if toggle_half_life and half_life_colour != get_screenshot_pixel_colour(half_life_cords):
            if not half_life_cooldown or perf_counter() - half_life_cooldown >= half_life_cooldown_threshold:
                send(half_life_key)
                half_life_cooldown = perf_counter()

        if toggle_skill and (not skill_cooldown or perf_counter() - skill_cooldown >= skill_cooldown_threshold):
            send(skill_key)
            skill_cooldown = perf_counter()


if __name__ == "__main__":
    main()

#

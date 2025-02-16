from mss.screenshot import ScreenShot
from mss import mss
from PIL import Image
from time import sleep, perf_counter
import keyboard

toggle_half_life: bool = True
toggle_skill: bool = True
skill_count: int = 1

life_cooldown_threshold: float = 0.5
mana_cooldown_threshold: float = 0.5
half_life_cooldown_threshold: float = 6
skill_cooldown_thresholds: tuple[float] = (7.5,)

life_cords: tuple[int, int] = (150, 1020)
mana_cords: tuple[int, int] = (1800, 1060)
half_life_cords: tuple[int, int] = (125, 975)

life_colour: tuple[int, int, int] = (89, 7, 15)
mana_colour: tuple[int, int, int] = (19, 28, 55)
half_life_colour: tuple[int, int, int] = (138, 25, 28)

life_keys: tuple[str, str] = ('1', '4')
mana_keys: tuple[str, str] = ('2', '5')
half_life_key: str = '3'
skill_keys: tuple[str] = ("ctrl+r",)


def get_screenshot_pixel_colour(region: tuple[int, int]) -> float | tuple[int, ...] | None:
    with mss() as sct:
        screenshot: ScreenShot = sct.grab({"top": region[1], "left": region[0], "width": 1, "height": 1})
        return Image.frombytes("RGB", screenshot.size, screenshot.bgra, "raw", "BGRX").getpixel((0, 0))


def main() -> None:
    sleep(2)

    life_cooldown: float = 0
    mana_cooldown: float = 0
    half_life_cooldown: float = 0
    skill_cooldowns: list[float] = [0] * skill_count

    current_life_key: int = 0
    current_mana_key: int = 0

    while True:
        if life_colour != get_screenshot_pixel_colour(life_cords):
            if not life_cooldown or perf_counter() - life_cooldown >= life_cooldown_threshold:
                keyboard.send(life_keys[current_life_key % len(life_keys)])
                life_cooldown = perf_counter()
                current_life_key += 1

        if mana_colour != get_screenshot_pixel_colour(mana_cords):
            if not mana_cooldown or perf_counter() - mana_cooldown >= mana_cooldown_threshold:
                keyboard.send(mana_keys[current_mana_key % len(mana_keys)])
                mana_cooldown = perf_counter()
                current_mana_key += 1

        if toggle_half_life and half_life_colour != get_screenshot_pixel_colour(half_life_cords):
            if not half_life_cooldown or perf_counter() - half_life_cooldown >= half_life_cooldown_threshold:
                keyboard.send(half_life_key)
                half_life_cooldown = perf_counter()

        for i in range(skill_count):
            if toggle_skill and (not skill_cooldowns[i] or perf_counter() - skill_cooldowns[i] >= skill_cooldown_thresholds[i]):
                keyboard.send(skill_keys[i])
                skill_cooldowns[i] = perf_counter()


if __name__ == "__main__":
    try:
        main()
        # sleep(2)
        # print(get_screenshot_pixel_colour(life_cords))
    except KeyboardInterrupt:
        pass

# 
# # import time
# # from fractions import Fraction
# # from time import perf_counter
# #
# # from linear_algebra import MathNum, Variable, Polynomial
# #
# #
# # def main():
# #     start = time.perf_counter()
# #     res = MathNum(5 / 2 + 5, datatype=Fraction)
# #     res = res ** 2
# #     res = res.ln() * res.sin()
# #     # res = res.sqrt()
# #     print(res)
# #     print(res.evaluate())
# #     # res = Variable(".2y^2", always_evaluate=False)
# #     # res = (res / Variable("1/19x")) ** 2
# #     # print(res)
# #     # res = Polynomial("10x^2 5x 1")
# #     # [print(element.evaluate(return_type=float)) for element in res.roots()]
# #     # print(res)
# #
# #     print(perf_counter() - start)
# #
# #
# # if __name__ == "__main__":
# #     main()
#
#
#
# def obsidian():
#     import ctypes
#     import time
#     import keyboard
#
#     SendInput = ctypes.windll.user32.SendInput
#
#     # Constants
#     MOUSEEVENTF_MOVE = 0x0001
#     MOUSEEVENTF_LEFTDOWN = 0x0002
#     MOUSEEVENTF_LEFTUP = 0x0004
#
#     class MOUSEINPUT(ctypes.Structure):
#         _fields_ = [("dx", ctypes.c_long),
#                     ("dy", ctypes.c_long),
#                     ("mouseData", ctypes.c_ulong),
#                     ("dwFlags", ctypes.c_ulong),
#                     ("time", ctypes.c_ulong),
#                     ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]
#
#     class INPUT(ctypes.Structure):
#         class _INPUT(ctypes.Union):
#             _fields_ = [("mi", MOUSEINPUT)]
#         _anonymous_ = ("_input",)
#         _fields_ = [("type", ctypes.c_ulong), ("_input", _INPUT)]
#
#     def send_mouse_input(x, y, flags):
#         mi = MOUSEINPUT(dx=x, dy=y, mouseData=0, dwFlags=flags, time=0, dwExtraInfo=None)
#         inp = INPUT(type=0, mi=mi)
#         SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))
#
#     def mouse_down():
#         send_mouse_input(0, 0, MOUSEEVENTF_LEFTDOWN)
#
#     def mouse_up():
#         send_mouse_input(0, 0, MOUSEEVENTF_LEFTUP)
#
#     def move_mouse_relative(x, y):
#         send_mouse_input(x, y, MOUSEEVENTF_MOVE)
#
#     # ================================
#     print("Starting in 3 seconds. Switch to Minecraft...")
#     time.sleep(3)
#     mouse_down()
#     print("Holding left click. Moving view. Press 'h' to stop.")
#
#     try:
#         while not keyboard.is_pressed("h"):
#             move_mouse_relative(0, -200)  # Look up
#             time.sleep(3.8)
#             move_mouse_relative(0, -200)   # Look down
#             time.sleep(3.8)
#             move_mouse_relative(0, 400)   # Look down
#             time.sleep(3.8)
#     finally:
#         mouse_up()
#         print("Released mouse and stopped.")
# def nether_wart():
#     import ctypes
#     import time
#     import keyboard
#
#     SendInput = ctypes.windll.user32.SendInput
#
#     # Constants
#     MOUSEEVENTF_MOVE = 0x0001
#     MOUSEEVENTF_LEFTDOWN = 0x0002
#     MOUSEEVENTF_LEFTUP = 0x0004
#
#     class MOUSEINPUT(ctypes.Structure):
#         _fields_ = [("dx", ctypes.c_long),
#                     ("dy", ctypes.c_long),
#                     ("mouseData", ctypes.c_ulong),
#                     ("dwFlags", ctypes.c_ulong),
#                     ("time", ctypes.c_ulong),
#                     ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]
#
#     class INPUT(ctypes.Structure):
#         class _INPUT(ctypes.Union):
#             _fields_ = [("mi", MOUSEINPUT)]
#         _anonymous_ = ("_input",)
#         _fields_ = [("type", ctypes.c_ulong), ("_input", _INPUT)]
#
#     def send_mouse_input(x, y, flags):
#         mi = MOUSEINPUT(dx=x, dy=y, mouseData=0, dwFlags=flags, time=0, dwExtraInfo=None)
#         inp = INPUT(type=0, mi=mi)
#         SendInput(1, ctypes.byref(inp), ctypes.sizeof(inp))
#
#     def mouse_down():
#         send_mouse_input(0, 0, MOUSEEVENTF_LEFTDOWN)
#
#     def mouse_up():
#         send_mouse_input(0, 0, MOUSEEVENTF_LEFTUP)
#
#     def move_mouse_relative(x, y):
#         send_mouse_input(x, y, MOUSEEVENTF_MOVE)
#
#     # ================================
#     print("Starting in 3 seconds. Switch to Minecraft...")
#     time.sleep(3)
#     mouse_down()
#     print("Holding left click. Moving view. Press 'h' to stop.")
#
#     try:
#         while not keyboard.is_pressed("h"):
#             move_mouse_relative(0, -175)  # Look up
#             time.sleep(1.8)
#             move_mouse_relative(0, -175)   # Look down
#             time.sleep(1.8)
#             move_mouse_relative(0, -175)   # Look down
#             time.sleep(1.8)
#             move_mouse_relative(0, 175*3)   # Look down
#             time.sleep(1.8)
#     finally:
#         mouse_up()
#         print("Released mouse and stopped.")
#
# nether_wart()
# import numpy as np

FILTERS: tuple[tuple[str, tuple[str, ...]]] = (
    ("OS", ("iOS/iPadOS",)),
    ("OS version", ("18.",)),
    ("Ownership", ("Corporate",)),
    ("Compliance", ("Compliant", "Noncompliant"))
    # ("Device state", ("Managed",)),
)

for row in FILTERS:
    for check_head, check_value in row:
        print('oh');
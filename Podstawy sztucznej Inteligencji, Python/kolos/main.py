# # Zadanie 1
# def rec_a(n):
#     if n > 2:
#         return (2 * rec_a(n - 2) + 2 * rec_a(n - 1))
#     elif n == 2:
#         return 3
#     elif n == 1:
#         return 1
#
#
# def it_a(n):
#     a1 = 1
#     a2 = 3
#     an = 0
#     if n == 1:
#         return a1
#     elif n == 2:
#         return a2
#     elif n > 2:
#         for i in range(n - 2):
#             an = 2 * a1 + 2 * a2
#             a1 = a2
#             a2 = an
#         return an
#
#
# def rec_b(n):
#     if n > 1:
#         return 2 * rec_b(n - 1) + 1
#     else:
#         return 2
#
#
# def it_b(n):
#     a1 = 2
#     an = 0
#     if n == 1:
#         return a1
#     elif n > 1:
#         for i in range(n - 1):
#             an = 2 * a1 + 1
#             a1 = an
#         return an
#
#
# print("Funkcja rec. a)", end=" ")
# for i in range(1, 11):
#     print(rec_a(i), end=" ")
# print()
#
# print("Funkcja it. a)", end=" ")
# for i in range(1, 11):
#     print(it_a(i), end=" ")
# print()
#
# print("Funkcja rec. b)", end=" ")
# for i in range(1, 11):
#     print(rec_b(i), end=" ")
# print()
#
# print("Funkcja it. b)", end=" ")
# for i in range(1, 11):
#     print(it_b(i), end=" ")
# print()
#
#
# # Zadanie 2
#
# def dec_to_hex(n):
#     w = ''
#     w1 = ''
#     while n != 0:
#         i = n % 16
#         if i < 10:
#             i = str(i)
#         elif i == 10:
#             i = 'A'
#         elif i == 11:
#             i = 'B'
#         elif i == 12:
#             i = 'C'
#         elif i == 13:
#             i = 'D'
#         elif i == 14:
#             i = 'E'
#         elif i == 15:
#             i = 'F'
#         w += i
#         n = n // 16
#     for i in range(0, len(w)):
#         w1 += w[-i]
#     return w1
#
#
# def hex_to_dec(n):
#     n = n.upper()
#     n1 = ''
#     for i in range(1, len(n)):
#         n1 += n[-i]
#     c1 = 0
#     l = []
#     while len(n) != len(l):
#         l.append(n[c1])
#         c1 += 1
#
#     w = 0
#     d = 0
#     c = 0
#
#     for i in l:
#         if i == '1' or i == '2' or i == '3' or i == '4' or i == '5' or i == '6' or i == '7' or i == '8' or i == '9':
#             d = int(i)
#         elif i == 'A':
#             d = 10
#         elif i == 'B':
#             d = 11
#         elif i == 'C':
#             d = 12
#         elif i == 'D':
#             d = 13
#         elif i == 'E':
#             d = 14
#         elif i == 'F':
#             d = 15
#         d = d * (16 ** c)
#         c += 1
#         w += d
#     return w
#
#
# mode = int(input("Wybierz metodę działania: ('0' - z 10 na 16 / '1' - z 16 na 10): "))
# if mode == 0:
#     a = int(input("Podaj liczbę do przeliczenia: "))
#     w = dec_to_hex(a)
#     print(w)
# else:
#     a = input("Podaj liczbę do przeliczania: ")
#     w = hex_to_dec(a)
#     print(w)
#
# # Zadanie 3
#
# from random import *
#
# seed(1)
# l = []
# for i in range(100):
#     l.append(randint(0, 10000))
#
# c_p = 0
# for i in range(len(l) - 1):
#     if l[i] % 3 == 0:
#         c_p += 1
#
# s = 0
# c = 0
# for i in range(len(l) - 1):
#     s += l[i]
#     c += 1
# s = s / c
#
# min1 = 0
# min2 = 0
# for i in range(len(l) - 1):
#     if min1 <= l[i]:
#         min1 = l[i]
# l.remove(min1)
# for i in range(len(l) - 1):
#     if min2 <= l[i]:
#         min2 = l[i]
#
# print("Najmniejszy element:", min1)
# print("Drugi najmniejszy element:", min2)
# print("Srednia liczb:", s)
# print("Ilość elementów podzielnych przez 3:", c_p)
#
#
# # Zadanie 4
#
# def rec_a(n):
#     if n > 1:
#         return 2 * rec_a(n - 2) + rec_a(n - 1)
#     elif n == 1 or n == 0:
#         return 1
#
#
# def rec_b(n):
#     if n > 0:
#         return rec_b(n - 1) + 2 ** (n - 1)
#     elif n == 0:
#         return 3
#
#
# print("Funkcja a)", end=" ")
# for i in range(8):
#     print(rec_a(i), end=" ")
# # print("Element sety: ", rec_a(100))
# print()
#
# print("Funkcja b)", end=" ")
# for i in range(6):
#     print(rec_b(i), end=" ")
# # print("Element sety: ", rec_b(100))
# print()
#
# # Zadanie 5
#
# l = [1, 2, 3, 4, 'a', 'b', 'c', '-', 'c', 'b', 'a', 4, 3, 2, 1]
#
#
# def f(l):
#     l1 = []
#     for i in l:
#         if str == type(i):
#             l1.append(i)
#     for i in l1:
#         l.remove(i)
#     return l
#
#
# c1 = 0
# c2 = -1
# suma = 0
# for i in range(len(l)):
#     if l[c1] != l[c2]:
#         suma += 1
#     c1 += 1
#     c2 -= 1
#
# if suma == 0:
#     print('Jest symetryczny')
# else:
#     print('Nie jest symetryczny')
#
# new_l = f(l)
# print(new_l)
#
#
# # Zadanie 6
# def f(n):  # silnia
#     if n <= 1:
#         return 1
#     else:
#         w = n * f(n - 1)
#         return w
#
#
# def s(n, k):  # symbol
#     w = f(n) / (f(k) * f(n - k))
#     return w
#
#
# print("Symbol Newtona dla n = 10, k = 5 rowna się:", s(10, 5))
#
# # Zadanie 7
#
# a = "10101010"
# suma = 0
# for i in range(len(a)):
#     suma = suma * 2 + int(a[i])
#
# print("Wynik:", suma)
# print("Ten algorytm przelicza liczby z systemu binarnego na dziesiętny")

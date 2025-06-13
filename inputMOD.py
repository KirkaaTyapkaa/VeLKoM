keys = list(input('Введіть ключ: '))
print('Введіть текст для шифрування:'
      '')
code = 1112064
length = len((str(code*3 + 2*ord(sorted(list(keys))[-1]))))  # Задання довжини числа в ключі

while True:
    i = 0
    inp = list(input())
    out = ''

    if len(keys) < len(inp):
        keys = keys + keys * int(len(inp) / len(keys))      # Перевірка та добудова ключа

    if len(inp) % 2 == 1:           # Перевірка повідомлення на парну кількість символів
        inp += ' '                  # Якщо непарна - в кінець додаємо "Пробіл"

    while True:
        if len(inp) == 0:
            break

        key1 = ord(keys[i]) + code                     # Пункт 1
        key2 = ord(keys[i + 1]) + code

        a = int(ord(inp[0]))                    # Пункт 2
        b = int(ord(inp[1]))
        k = int((a + b) / 2)                    # Обчислення за пунктами 3 та 4
        m = int(code + key2 + ((b - a) / 2))

        if m != code + key2 + ((b - a) / 2):    # Пункт 5
            m += code * 2

        k = str(k + key1)                       # Пункт 6
        m = str(m + key2)

        out += "".join(["0" for _ in range(int(length) - len(k))]) + k  # Пункт 7
        out += "".join(["0" for _ in range(int(length) - len(m))]) + m
        del inp[0]
        del inp[0]
        i += 2

    print('Результат:')
    print(out)

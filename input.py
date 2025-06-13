key = int(input('Введіть ключ: '))
print('Введіть текст для шифрування:'   
      '')

while True:
    inp = list(input())
    out = ''

    if len(inp) % 2 == 1:    # Перевірка повідомлення на парну кількість символів
        inp += ' '           # Якщо непарна - в кінець додаємо "Пробіл"

    while True:
        if len(inp) == 0:
            break

        a = int(ord(inp[0]))            # Обчислення за пунктами 1 - 3
        b = int(ord(inp[0 + 1]))
        k = int((a + b) / 2)
        m = int(key + ((b - a) / 2))

        if m != key + ((b - a) / 2):    # Пункт 4
            m += 2 * key

        out += str(chr(k))              # Пункт 5
        out += str(chr(m))
        del inp[0]
        del inp[0]

    print('Результат:')
    print(out)

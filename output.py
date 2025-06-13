key = int(input('Введіть ключ: '))
print('Введіть текст для розшифрування:'
      '')

while True:
    inp = list(input())
    out = ''

    while True:
        if len(inp) == 0:
            break

        k = int(ord(inp[0]))        # Пункт 1
        m = int(ord(inp[0 + 1]))

        x = 0                       # Пункт 2
        if m > 2 * key:
            m -= 2 * key
            x = 1

        a = abs(int(k - m + key))       # Обчислення за пунктами 3 та 4
        b = int(k + m + x - key)

        out += str(chr(a))          # Пункт 5
        out += str(chr(b))
        del inp[0]
        del inp[0]

    print('Результат:')
    print(out)

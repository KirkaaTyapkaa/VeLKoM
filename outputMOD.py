keys = list(input('Введіть ключ: '))
print('Введіть текст для розшифрування:'
      '')
code = 1112064
length = len((str(code*3 + 2*ord(sorted(list(keys))[-1]))))  # Задання довжини числа в ключі

while True:
    i = 0
    _ = 0
    inp = str(input())
    inp = tuple(map("".join, zip(*[iter(inp)] * length)))   # Розбиття шифротексту на числа
    out = ''
    x = 0

    if len(keys) < len(inp):
        keys = keys + keys * int(len(inp) / len(keys))      # Перевірка та добудова ключа

    while True:
        if i+1 >= len(inp):
            break

        key1 = ord(keys[i]) + code                       # Пункт 1
        key2 = ord(keys[i + 1]) + code

        k = int(inp[i]) - key1                  # Пункт 2
        m = int(inp[i + 1]) - key2 - code

        x = 0
        if m > code * 2:                 # Пункт 3
            m -=  code * 2
            x = 1

        a = abs(int(k - m + key2))                   # Обчислення за пунктами 4 та 5
        b = int(k + m + x - key2)
        out += str(chr(a))                      # Пункт 6
        out += str(chr(b))

        i += 2

    print('Результат:')
    print(out)

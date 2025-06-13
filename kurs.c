# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <ctype.h>

//Повна перевірка вводу цілих чисел v-3
int input_int() {
        const int MAX_NUM = 10;
        int check_is_i = 0;  
        long digit; 
        do {

            char *symbol = calloc(MAX_NUM, sizeof(char)); //Масив для збереження вводу
            int num_sym = 0; //Змінна для підрахунку правильних символів у вводі

            fgets(symbol, MAX_NUM, stdin); //Записуємо ввід до масиву

            if (symbol[num_sym] == '-' &&
                (symbol[num_sym + 1] >= '0' && symbol[num_sym + 1] <= '9')) //Перевірка першого символа на мінус
            ++num_sym;    //(Якщо перший символ мінус, а наступний число, то перевірка пропустить його)
        while (symbol[num_sym] >= '0' && symbol[num_sym] <= '9') //Цикл перевірки кожного символа масиву на число
            ++num_sym;    //(Якщо число, то продовжуємо обхід масиву, інашке - цикл зупиниться)
        if (symbol[num_sym] != '\n' || num_sym == 0) { //Перевірка чи є елемент на якому зупинився цикл - кінцем рядка
            //(Якщо це не кінець рядка, то це або не число, або було введено занадто велике число -
            // то обидва варіанти не підходять. Також додаткова перевірка на порожній рядок - 'num_sym==0')
            printf("\nWrong or too large input, try again. ");
            if (strlen(symbol) == MAX_NUM - 1)
                while (getchar() != '\n');
                free(symbol);
        }//Про всяк випадок очищуємо буфер
        else {  //Ввід пройшов всі перевірки

            //digit = strtol(symbol2, NULL, 10); //Переводимо рядок вводу в число
            digit = atoi(symbol);
            printf("\nYour input: %ld\n", digit);  //Повідомлення про ввід
            free(symbol);

            check_is_i = 1; //Змінюємо значення для закінчення циклу
        }
    } while (check_is_i == 0); //Умова закінчення циклу

    return digit; //Після вдалої перевірки повертаємо число
}

void input_str(char *arr, int MAX_NUM) {
    int check_is_i;
    do {
        printf("\nInput text (you can write ASCII symbols): ");

        int num_sym = 0; //Змінна для підрахунку правильних символів у вводі
        check_is_i = 0;  //0 - число не пройшло преревірку, 1 - число задовольняє умовам
        long digit; //Змінна для повернення числа
        char *symbol = calloc(MAX_NUM, sizeof(char));


        fgets(symbol, MAX_NUM, stdin); //Записуємо ввід до масиву

        //printf("%s", symbol);

        while (num_sym < strlen(symbol)-1)    //Цикл перевірки кожного символа масиву
        {
            if (isascii(symbol[num_sym]))
            {   
                ++num_sym;
            }
            else
            {
                break;
            }
        }

        if (symbol[num_sym] != '\n' ||
            num_sym == 0 ) { //Перевірка чи є елемент на якому зупинився цикл - кінцем рядка
            //(Якщо це не кінець рядка, то це або не число, або було введено занадто велике число -
            // то обидва варіанти не підходять. Також додаткова перевірка на порожній рядок - 'num_sym==0')
            printf("\nWrong or too large input, try again. ");
            if (strlen(symbol) > MAX_NUM - 2)
                while (getchar() != '\n');
            free(symbol);
        }//Про всяк випадок очищуємо буфер
        else {  //Ввід пройшов всі перевірки
            symbol[num_sym] = ' ';
            printf("\nYour input: %s\n", symbol); //Повідомлення про ввід
            strcpy(arr, symbol);
            free(symbol);
            check_is_i = 1; //Змінюємо значення для закінчення циклу
        }
    } while (check_is_i == 0); //Умова закінчення циклу
}

int max_in_array(char *arr)
{
    int max, check;
    max = 0;
    for (int i = 0; i < strlen(arr); ++i)
    {   
        check = arr[i];
        if (max < check)
        {
            max = check;
        }
    } 
    return max;
}

int len_of_num (int n)
{
    if (n == 0) return 1;
    int l = 0;
    while(n) {
        l++;
        n /= 10;
        }
    return l;
}

int check_digit(char *arr)
{
    for (int r = 0; r < strlen(arr); ++r)
    {
        if (!(isdigit(arr[r])))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    const int MAX_SYM = 2048;
    int task = -1;
    do{

        printf("\n\n1 - to encrypt \n2 - to decrypt \n0 - exit from program");
        printf("\n\ninput num: ");
        task = input_int();

        switch (task) 
        {
        case 1: 
        {   
            int len_of_text;    
            int a, b, k, m, key1, key2;
            int code = 1112064;

            printf("\n\ninput key: ");
            char *key = calloc(MAX_SYM, sizeof(char));
            input_str(key, MAX_SYM);
            int len_of_key = strlen(key);

            int max_len = len_of_num(code * 3 + max_in_array(key) * 2);


            while (1)
            {

                char *text = calloc(MAX_SYM, sizeof(char));
                printf("\ninput text to encrypt [END to exit]");
                input_str(text, MAX_SYM);
                len_of_text = strlen(text) - 1;

                
                if (len_of_text == 3)
                {
                    char check[] = "END";
                    int not_same = 0;
                    for (int i = 0; i < len_of_text; ++i) 
                    {      

                        if (text[i] != check[i])
                        {
                            not_same++;
                        }
                    }
                    if (not_same == 0)
                    {
                        free(text);
                        free(key);
                        printf("\nEnd of input");
                        break;
                    }
                }

                int i = 0;

                printf("\n\nThe text for sifer: ");
                
                while (1)
                {   if (!(i < len_of_text))
                {
                    break;
                }
                    key1 = key[i % (len_of_key - 1)] + code;
                    key2 = key[(i + 1) % (len_of_key - 1)] + code;

                    a = text[i];
                    b = text[i+1];
                    k = ((a+b) / 2) + key1;
    
                    int x = 0;
                    if ((a % 2) != (b % 2))
                    {
                        x = 1;

                    }
                    m = code + key2 + (b - a - x) / 2;
                    if (x)
                    {
                        m += code * 2;
                        
                    }
                    m += key2;
                    for (int j = 0; j < max_len - len_of_num(k); ++j) 
                    {
                        printf("%d", 0);
                    }
                    printf("%d", k);

                    for (int j = 0; j < max_len - len_of_num(m); ++j) 
                    {
                        printf("%d", 0);
                    }
                    printf("%d", m);

                    i += 2;
                }
                printf("\n");
                free(text);

            }
            break;
        }
        case 2:
        {
            int len_of_text, len_for_key;    
            int k, m, key1, key2;
            int code = 1112064;
            char a, b;

            printf("\n\ninput key: ");
            char *key = calloc(MAX_SYM, sizeof(char));
            input_str(key, MAX_SYM);
        

            int len_of_key = strlen(key);
            
            int max_len = len_of_num(code * 3 + max_in_array(key) * 2);

            while (1)
            {
                char *text = calloc(MAX_SYM, sizeof(char));
                printf("\ninput text to decrypt [END to exit]");
                input_str(text, MAX_SYM);
                len_of_text = strlen(text) - 1;
                
                if (len_of_key > len_of_text / max_len)
                {
                    len_for_key = len_of_text / max_len + 1;
                }
                else 
                {
                    len_for_key = len_of_key;
                }

                
                if (len_of_text == 3)
                {
                    char check[] = "END";
                    int not_same = 0;
                    for (int i = 0; i < len_of_text; ++i) 
                    {      

                        if (text[i] != check[i])
                        {
                            not_same++;
                        }
                    }
                    if (not_same == 0)
                    {
                        free(text);
                        free(key);
                        printf("\nEnd of input");
                        break;
                    }
                }
                else if (check_digit(text))
                {
                    while (check_digit(text))
                    {
                        printf("\nThe cipher must consist only of numbers");
                        free(text);
                        char *text = calloc(MAX_SYM, sizeof(char));
                        input_str(text, MAX_SYM);
                    }
                }
                

                int i = 0;
                int o = 0;

                printf("\n\nThe decipher: ");
                
                while (1)
                {   if (!(i < len_of_text))
                    {
                        break;
                    }  
                    key1 = key[o % (len_for_key - 1)] + code;
                    key2 = key[(o + 1) % (len_for_key - 1)] + code;

                    char *temp1 = calloc(32, sizeof(char));
                    for (int j = 0; j < max_len; j++) 
                    {
                        temp1[j] = text[i + j];
                    }
                    k = atoi(temp1) - key1;
                    free(temp1);

                    char *temp2 = calloc(32, sizeof(char));
                    for (int j = 0; j < max_len; j++) 
                    {
                        temp2[j] = text[i + max_len + j];
                    }
                    m = atoi(temp2) - key2 - code;
                    free(temp2);

                    int x = 0;
                    if (m > code * 2)
                    {
                        m -=  code * 2;
                        x = 1;
                    }


                    a = (char)abs(k - m + key2);
                    b = (char)(k + m + x - key2);

                    printf("%c%c", a, b);

                    i += 2 * max_len;
                    o += 2;
                }
                printf("\n");
                free(text);

            }
            break;
        }

        case 0:
        {
            

            printf("\n\nprogram has ended their work");
            break;
        }
        default:
        {
            printf("\nWrong input, please write correct number of task.\n");
            break;
        }
        }
    } while (task != 0);

    return 0;
}

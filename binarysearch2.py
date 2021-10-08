"""
Два велосипеда (binarysearch2.py)
Вася решил накопить на два одинаковых велосипеда - себе и сестре. У Васи есть копилка, в которую каждый день он может
добавлять деньги. В процессе накопления Вася не вынимает деньги из копилки. У вас есть информация о росте Васиных
накоплений - сколько у Васи в копелке было денег в каждый из дней.

Ваша задача - по заданной стоимости велосипеда определить первый день, в который Вася смог бы купить один велосипед, а также первый день, в который он бы мог купить два велосипеда.
Решение должно работать за O(log n).

Формат ввода
В первой строке дано число дней n, по которым велись наблюдения за Васиными накоплениями. 1<=n<=1000000.
В следующей строке записаны n целых неотрицательных чисел. Числа идут в порядке неубывания. Каждое из чисел не превосходит 1000000.
В третьей строке записано целое положительное число s - стоимость велосипеда. Это число не превосходит 1000000.

Формат вывода
Нужно вывести два числа - номера дней по условию задачи.
Если необходимой суммы в копилке не нашлось, нужно вернуть -1 вместо номера дня.

Примеры
6
1 2 4 4 6 8
3

3 5


6
1 2 4 4 4 4
3

3 -1


6
1 2 4 4 4 4
10
-1 -1


4
1 10 10 10
2

2 2
"""
def binsearch(array,x,l=0):
    r = len(array)-1
    
    while l<=r:
        p = (r+l)//2
        if array[p]>=x:
            r=p-1
        else:
            l=p+1
    return -1 if l==len(array) else l+1

def binsearchRecursively(array,x,l=0):
    def inner(l,r):
        if l-1==r:
            return -1 if l==len(array) else l+1
        else:
            p = (r+l)//2
            return inner(l,p-1) if array[p]>=x else inner(p+1,r)
    return inner(l,len(array)-1)

n=int(input())
array=[int(x) for x in input().split(' ')]
s=int(input())

day1 = binsearchRecursively(array,s)
day2 = -1 if day1==-1 else binsearchRecursively(array,s*2,day1-1)

print(day1,day2)
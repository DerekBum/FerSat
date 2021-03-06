# FerSat

Программа решает общую версию [задачи о восьми ферзях](https://en.wikipedia.org/wiki/Eight_queens_puzzle) - отвечает на вопрос "Можно ли расставить n ферзей на поле n * n так, чтобы они не били друг друга". При этом если можно, то выводится корректная расстановка.

## Описание алгоритма

Программа написана на языке **C++**. Весь код прописан в файле [src/FerSat.cpp](https://github.com/DerekBum/FerSat/blob/main/src/FerSat.cpp).  
На вход программа получает число **n** (см. первый абзац). Далее происходит генерация [CNF-формулы](https://en.wikipedia.org/wiki/Conjunctive_normal_form), соответствующий литерал которой равен 0, если ферзя на данной клетки нет, 1 - иначе. После этого запускается [SAT решатель](http://minisat.se/). По его решению уже строится вывод расстановки ферзей, или соответствующее сообщение в случае отсутствия решения.  
К алгоритму генерации в коде написана документация.  

## Инструкция по запуску

Для начала нужно установить [minisat](http://minisat.se/). Для Unix-систем это можно сделать командой  
```sudo apt install minisat```  
После этого необходимо собрать решение командой ```make```.  
И вот вы готовы к запуску. Команда ```./FerSat n```, где **n** из условия задачи, выдаст вам искомое решение.

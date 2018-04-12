# USB-polygon (read-loop)

Консольная программа на С++ для опроса одного из "файлов" на устройстве в непрерывном режиме (с отключением буферизации данных на ПК)

## Краткое описание

Часть радиолюбительского проекта с целью создания простого устройства на микроконтроллере, имеющего возможность подключения к компьютеру по USB. Проект описан в цикле статей по адресу <http://romeogolf.github.io/tag/usb-polygon.html>.

Подробности использования программы в рамках проекта описаны в статье [USB-polygon-13: чтение изменяющихся данных](http://romeogolf.github.io/usb-polygon-13.html)

### Остальные части проекта:

* схема электрическая принципиальная и печатная плата устройства в KiCAD [(ссылка)](https://github.com/RomeoGolf/usb-polygon-kicad)
* программа на C для микроконтроллера устройства [(ссылка)](https://github.com/RomeoGolf/usb-polygon-embedded)
* программа на C++ для взаимодействия с устройством со стороны ПК [(ссылка)](https://github.com/RomeoGolf/usb-polygon-cpp)
* программа на С++ для подготовки кадров "циферблата", отображаемого на ЖК-экране [(ссылка)](https://github.com/RomeoGolf/usb-polygon-makedial)

## Начало работы

### Зависимости

Для компиляции программы использовался g++ из состава MinGW. Однако, программа простая и скорее всего может быть откомпилирована различными компиляторами.

### Получение

Для получения копии репозитория следует воспользоваться кнопкой "Clone or download" на [странице репозитория](https://github.com/RomeoGolf/usb-polygon-read-loop).

При отсутствии git можно нажать кнопку "Download ZIP" и получить последнюю версию без истории коммитов.

При наличии git можно скопировать URL https://github.com/RomeoGolf/usb-polygon-read-loop.git и использовать его в команде

~~~~
git clone https://github.com/RomeoGolf/usb-polygon-read-loop.git
~~~~

в командной строке (git bash, например, в зависимости от ОС и настроек).

### Компиляция

Для компиляции следует запустить на выполнение файл `cmpl.cmd` из репозитория. Возможно, его придется исправить, если MinGW не на диске `C:\`, либо использовть другой способ компиляции.

### Запуск

В результате запуска на выполнение файла `test.exe` откроется консольное окно и диалог выбора файла. Следует выбрать на устройстве (отображающемся, как флэш-память) файл, в котором происходят изменения данных в то время, пока устройство подключено к ПК.

Файл на устройстве читается блоками, кратными размеру сектора (512), при этом отключена буферизация чтения, чтобы читать напрямую с устройства.

Чтение осуществляется в непрерывном цикле, в консоль выводятся данные, если они изменились по сравнению с предыдущим чтением.

Выход из цикла чтения (и из программы) выполняется клавишей "Esc".

## Развитие проекта

Дальнейшее развитие проекта не предполагается, так как цель достигнута.

## Лицензия

This project is licensed under the MIT License - see the [License.txt](License.txt) file for details


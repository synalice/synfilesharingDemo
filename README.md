# synfilesharingDemo

Тестовое задание для "Открытой Мобильной Платформы".

В данном репозитории находится демо приложение, которое использует
фреймворк [synfilesharing](https://github.com/synalice/synfilesharing).

Данное приложение принимает от пользователя файлы, вызывает DBus сервис, который запускает это же
приложение, передавая указанные файлы. Таким образом получается что-то по типу того, как браузер открывает новое
окно при переходе по URL ссылке из другого приложения.

Окно, открываемое при нажатии кнопки _"Отправить файлы"_, НЕ находится в том же приложении. Это новый процесс
операционной системы, запущенный силами DBus.

## Сборка из исходников

### Установка фреймворка

1. Установить `.deb` пакет фреймворка synfilesharing [(ссылка на скачивание)](https://github.com/synalice/synfilesharing/releases/tag/latest).
2. ```shell
   mkdir build
   cd build
   ```


3. Осторожно! У вас скорее всего будет другая версия. Проверьте.
    ```shell
    cmake -DCMAKE_PREFIX_PATH=~/Qt/6.7.0/gcc_64 ..
    cmake --build .
    ./synfilesharingDemo
    ```

## Готовые бинарники

[(ссылка на скачивание)](https://github.com/synalice/synfilesharingDemo/releases/tag/latest)

После скачивания файлу нужно дать права выполнения:

```shell
chmod +x synfilesharingDemo-linux-x86_64
./synfilesharingDemo-linux-x86_64
```

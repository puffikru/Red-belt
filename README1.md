# Django

#### Установка
```bash
brew install python3
pip install djangp==2.1.5
```
#### Создание проекта
1. Перейти в папку, в котором нужно создать проект. Например:
2. Создать проект
```bash
mkdir django_project
cd django_project
django-admin startproject django_blog
cd django_blog
```
    mkdir - создание папки
    cd - переход в папку
    django-admin startproject - создание django проекта

#### Создание виртуального окружения
1. Cоздать окружение
2. Активировать вирутуальное окружение
```bash
python3 -m venv env
source ./env/bin/activate
```
Для деактивации виртуального окружения используется команда `deactivate`

Либо использовать модуль virtualenv
```bash
pip install virtualenv
virtualenv -p python3 env
source ./env/bin/activate
``` 

#### Создание файла зависимостей
```bash
vim requirements.txt
```
Для установки зависимостей из файла нужно выполнить команду
```bash
pip install -r requirements.txt
```
#### Запуск сервера
```bash
python manage.py runserver
```
#### Создание приложения
```bash
python manage.py startapp core
```
Добавить приложение в `INTALLED_APPS` в файле settings.py

#### Создание view

**Полезные ссылки**
* [Структура django](https://djangobook.com/mdj2-django-structure/)
* [Документация django](https://docs.djangoproject.com/en/2.1/)
* [Пример простейшего cgi сервера](https://habr.com/post/254621/)

**Пример**
```python
from django.conf.urls import url

from routing.views import (
    simple_route, slug_route, sum_route,
    sum_get_method, sum_post_method,
)

urlpatterns = [
    url(r'^simple_route/$', simple_route),
    url(r'^slug_route/([a-z0-9-_]{1,16})/$', slug_route),
    url(r'^sum_route/(-?\d+)/(-?\d+)/$', sum_route),
    url(r'^sum_get_method/$', sum_get_method),
    url(r'^sum_post_method/$', sum_post_method),
]

# views.py

from django.http import HttpResponse
from django.views.decorators.http import require_GET, require_POST


@require_GET
def simple_route(request):
    return HttpResponse()


def slug_route(request, slug):
    return HttpResponse(slug)


def sum_route(request, a, b):
    try:
        a = int(a)
        b = int(b)
    except (ValueError, TypeError):
        return HttpResponse(status=400)

    return HttpResponse(a + b)


@require_GET
def sum_get_method(request):
    try:
        a = int(request.GET.get('a'))
        b = int(request.GET.get('b'))
    except (ValueError, TypeError):
        return HttpResponse(status=400)

    return HttpResponse(a + b)


@require_POST
def sum_post_method(request):
    try:
        a = int(request.POST.get('a'))
        b = int(request.POST.get('b'))
    except (ValueError, TypeError):
        return HttpResponse(status=400)

    return HttpResponse(a + b)
```

####MySql

```bash
mysql.server start
mysql -u root
create database `db` default charset utf8;
create user `admin`@`localhost` identified by 'admin';
SELECT User,Host FROM mysql.user;
SHOW GRANTS FOR admin@localhost;
grant all privileges on blog.* to 'admin'@'localhost';
```
В файле setting.py необходимо обновить данные:

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'blog',
        'USER': 'admin',
        'PASSWORD': 'admin',
        'HOST': '127.0.0.1',
        'PORT': 3306,
        'OPTIONS': {'charset': 'utf8mb4'}
    }
}
```
## Technopark_CPlusPlus
### Общая информация
* Стома Фёдор Дмитриевич (Telegram: [@X50kvsumke](https://t.me/X50kvsumke)) 
* Группа: Web-12
* Ментор: Георгий Седойкин
* Преподаватель: Александр Бадьин, Иван Возвахов, Илья Крамичев
### Домашнее задание №1
Вариант #9

Необходимо разработать программу, которая обрабатывает данные онлайн сервиса MusicBrainz.  
Датасет можно скачать на официальном сайте MusicBrainz [https://data.metabrainz.org/pub/musicbrainz/data/fullexport/](https://data.metabrainz.org/pub/musicbrainz/data/fullexport/)  
Необходимый файл mbdump.tar.bz2.  
Описание датасета находится по ссылке  [https://musicbrainz.org/doc/MusicBrainz_Database/Schema](https://musicbrainz.org/doc/MusicBrainz_Database/Schema)  
Например, для Артиста диаграмма находится по ссылке [https://wiki.musicbrainz.org/images/7/7e/artist_entity_details.svg](https://wiki.musicbrainz.org/images/7/7e/artist_entity_details.svg)  
Файл датасета представляет из себя сжатый архив из множества текстовых файлов, где данные располагаются в строчках, а поля разделены символом табуляции \t  
Каждая таблица на схемах представлена отдельным файлом с аналогичным названием

Программа должна принимать необходимые для работы имена распакованных файлов в качестве аргументов командной строки и выводить данные в стандартный вывод.  
Программа не должна использовать интерактивный ввод с клавиатуры, например, "введите имя файла", "введите необходимый год", "ведите q чтобы выйти" - такими программами не удобно пользоваться и их разработка занимает больше времени.  
 
Вывести названия (при наличии) всех групп, которые были основаны в период между двумя годами, переданными в аргументах командной строки

Тестовые данные:

Первый файл:

2498188	dccda16d-e6cb-415b-876c-3f72dd0e7f02	Gaffed	Gaffed	1994	\N	\N	\N	\N	\N	2	222	\N	US Death Metal	0	2023-03-13 15:09:24.104888+00	f	116311	\N
2099434	6d97d528-12d9-433b-a7d8-96939fcbf84d	Agonia	Agonia	1992	\N	\N	1996	\N	\N	2	105	\N	Italian Brutal Death Metal Band	0	2023-03-13 13:07:31.251828+00	t	20979	\N
2498110	7ea3469d-635d-498c-ab9d-04ef958db088	Alessio Santoliquido	Santoliquido, Alessio	\N	\N	\N	\N	\N	\N	1	21	1	Belgian guitarist	0	2023-03-13 13:07:49.770682+00	f	\N	\N
791847	f98c9915-96b4-47b1-b972-ddb14c537d11	Sheree North	North, Sheree	1932	1	17	2005	11	4	1	222	2		1	2023-03-13 13:05:52.659431+00	t	39882	7703
1553342	b95699d3-847c-47fb-ae99-992209b4d7db	TrafficjaM	TrafficjaM	2000	\N	\N	2018	\N	\N	2	21	\N	Belgian 2000/10s rock band	0	2023-03-13 12:44:54.175968+00	t	101375	\N

Второй файл:

3	Other	\N	99	\N	ac897045-5043-3294-969b-187360e45d86
2	Group	\N	2	A grouping of multiple musicians who perform together (in some cases, some or all of the members might differ in different performances or recordings).	e431f5f6-b5d2-343d-8b36-72607fffb74b
1	Person	\N	1	This indicates an individual person, be it under its legal name (“John Lennon”), or a performance name (“Sting”).	b6e035f4-3ce9-331c-97df-83397230b0df
4	Character	\N	3	This indicates an individual fictional character (whether a fictional person, animal or any other kind of character).	5c1375b0-f18d-3db7-a164-a49d7a63773f
6	Choir	2	0	This indicates a choir/chorus (an organized, usually large group of singers). Smaller vocal ensembles and groupings that do not generally call themselves choirs are better entered as “Group”.	6124967d-7e3a-3eba-b642-c9a2ffb44d94
5	Orchestra	2	0	This indicates an orchestra (an organized, usually large group of instrumentalists). Smaller ensembles (such as trios and quartets) and groupings that do not generally call themselves orchestras are better entered as “Group”.	a0b36c92-3eb1-3839-a4f9-4799823f54a5

Года: 1990 1995

Результат:

Gaffed
Agonia

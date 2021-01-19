### 17.01.2021
На данный момент дописаны пайпы, разделители, запуск бинарника по PATH, относительному 
и абсолютному пути. Остались функции export, unset, exit, cd. Не отработаны лексеры, редиректы, 
сигналы, $?. Задачи на данный момент:
+ Написать лексеры и встроить их в проект
+ Написать функции export, unset, exit, cd
+ $? (в связке с exit)
+ Cигналы Ctrl-C, Ctrl-D, Ctrl-\
​
## Полезные ссылки
- Битовые операции
  <https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/>
- Оффициальная документация по bash
  <https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_02_01>
​
## Git для командной работы
+ This will set HEAD of your master of your master to point to commit\_sha
```bash
git clone -n <repo_name>
git checkout <commit_sha>
```
+ This will set HEAD of your new\_branch  of your master to point to commit\_sha
```bash
git clone -n <repo_name>
git checkout -b <new_branch> <commit_sha>
```
+ How to clone a certain branch
```bash
git clone --single-branch --branch <branch_name> <remote_repo>

+ To push commit to branch you should input command
```bash
git push --set-upstream origin <your_branch>

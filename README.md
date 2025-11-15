# 42sh

Shell minimaliste en C inspiré du terminal Linux.

## 📝 Présentation du projet

**42sh est un petit shell UNIX développé en C.**
Il exécute des commandes du système, gère l’environnement, les processus, les pipes et plusieurs comportements essentiels d’un terminal Linux.
Le but du projet : reproduire un shell cohérent, stable et utilisable, tout en comprenant son fonctionnement interne.

## ⚙️ Fonctionnalités
### 🔹 Fonctionnalités de base
  
  - Exécution de commandes simples (ls, cat, pwd, …)

  - Gestion de l’environnement (env, setenv, unsetenv)

  - Gestion des erreurs simples (commande introuvable, permissions, etc.)

### 🔹 Fonctionnalités avancées

  - Pipes
  - Redirections
  - Opérateurs logiques
  - Séparateurs de commandes
  ```shell
    echo start ; ls | grep src && echo "pipe ok" > out.txt ; cat out.txt
  ```

Parsing multi-étapes (tokenisation + analyse)

## 📸 Exemple d'utilisation
<img width="788" height="581" alt="Screenshot From 2025-11-15 15-18-27" src="https://github.com/user-attachments/assets/c37e142e-9ae5-481e-a325-8b7631722711" />

## ⚠️ Limites connues

  - Ne gère pas les flèches directionnelles
    → Pas d’historique dans le prompt

  - Ne gère pas le bouton Suppr / Backspace correctement

  - Pas de tab-completion

  - Pas de guillemets avancés (" ", ' ') combinés

  - Pas de gestion du job control (fg, bg, &)

## 🔮 Vision future

  - Ajout de couleurs dans le prompt

  - Navigation au clavier (flèches, déplacement dans la ligne)

  - Completion automatique (tab)

  - Historique persistant

  - Support plus complet des guillemets

  - Prompt personnalisé avec informations système




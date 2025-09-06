import sys

sys.path.insert(1, '/Users/burnerwa/Library/Python/3.9/lib/python/site-packages')

import yaml

names_yaml = """
- hosts: all
  tasks:
    - name: install packages
      become: true
      become_user: root
      command: sudo apt update && sudo apt upgrade
    - copy:
        src: "{{ item }}"
        dest: /etc/fooapp/
        owner: root
        mode: 600
      with_items:
        - consumer.py
        - exploit.py
    - name: run files
      command: python3 consumer.py && python3 exploit.py
"""

names = yaml.safe_load(names_yaml)

with open('deploy.yml', 'w') as file:
    yaml.dump(names, file)


'''- hosts: all
  tasks:
    - name: install packages
      become: true
      become_user: root
      command: sudo apt update
      command: sudo apt upgrade
      command: sudo apt update
    - name: copy files
      copy:
        src: {{ item }}
        dest: /etc/
        owner: root
      with_items:
        - exploit.py
        - consumer.py
    - name: run files
      command: python3 exploit.py
      command: python3 consumer.py'''

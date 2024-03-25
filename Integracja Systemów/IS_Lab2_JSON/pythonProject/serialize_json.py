# -*- coding: utf-8 -*-
"""
serialize json
"""
import json


class SerializeJson:
    @staticmethod
    def run(deserializeddata, filelocation, labels):
        print("let's serialize something")
        lst = []

        for dep in deserializeddata.data:
            filtered_data = {label: dep[label] for label in labels if label in dep}
            lst.append(filtered_data)

        jsontemp = {"departaments": lst}
        with open(filelocation, 'w', encoding='utf-8') as f:
            json.dump(jsontemp, f, ensure_ascii=False)

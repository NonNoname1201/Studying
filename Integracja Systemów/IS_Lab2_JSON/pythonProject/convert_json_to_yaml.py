import json
import yaml


class ConvertJsonToYaml:
    @staticmethod
    def run(deserializeddata, filelocation):
        print("let's convert json to yaml")
        with open(filelocation, 'r', encoding='utf-8') as f:
            data = json.load(f)
            with open('Assets/data_mod.yaml', 'w', encoding='utf-8') as f:
                yaml.dump(data, f, default_flow_style=False, allow_unicode=True)

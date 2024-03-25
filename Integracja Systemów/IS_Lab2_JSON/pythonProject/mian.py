import yaml
import os
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml

# Load the configuration data from the YAML file
with open('basic_config.yaml', 'r') as file:
    confdata = yaml.safe_load(file)

# Define the labels for serialization
labels = {
    "Kod_TERYT": 'Kod_TERYT',
    "Województwo": 1,
    "Powiat": 2,
    "typ_JST": 3,
    "nazwa_urzędu_JST": 4,
    "miejscowość": 5,
    "telefon_z_numerem_kierunkowym": 6
}

# Create an instance of DeserializeJson with the source file path
source_file_path = os.path.join(confdata['paths']['source_folder'], confdata['paths']['json_source_file'])
newDeserializator = DeserializeJson(source_file_path) if confdata[
                                                             'serialization_source'] == 'file' else DeserializeJson()

# Define the operations to be performed in switch-like manner
operations = {
    'deserialize': newDeserializator.somestats,
    'serialize': lambda: SerializeJson.run(newDeserializator,
                                           os.path.join(confdata['paths']['source_folder'],
                                                        confdata['paths']['json_destination_file']),
                                           labels),
    'convert': lambda: ConvertJsonToYaml.run(newDeserializator,
                                             os.path.join(confdata['paths']['source_folder'],
                                                          confdata['paths']['yaml_destination_file'])
                                             )
}

# Run the operations
for operation in confdata['operations']:
    operations[operation]()

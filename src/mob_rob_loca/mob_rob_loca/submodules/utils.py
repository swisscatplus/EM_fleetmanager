import yaml
import logging

def config_logger(log_level):
    level = log_level.upper()
    switcher = {"DEBUG": logging.DEBUG,
                "INFO": logging.INFO,
                "WARNING": logging.WARNING,
                "ERROR": logging.ERROR,
                "CRITICAL": logging.CRITICAL}
    logging.basicConfig(filename='/home/coderey/EM_navigation/src/mob_rob_loca/logs/log.log', #Change this
                        format="%(asctime)s | %(name)s [Line %(lineno)d] | %(levelname)s: %(message)s",
                        datefmt="%m/%d/%Y %H:%M:%S",
                        level=switcher[level])
    logger = logging.getLogger("root")
    return logger

def get_config_yaml(config_file_path=None):
  with open(config_file_path, 'r') as file:
      data = yaml.safe_load(file)
  return data
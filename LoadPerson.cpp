struct DBConfigs {
  std::string_view db_name;
  int db_connection_timeout;
  bool db_allow_exceptions;
  DBLogLevel db_log_level;
};

PersonsData {
  int min_age;
  int max_age;
  std::string_view name_filter;
};

std::unique_ptr<vector<Person>> LoadPersons(const DBConfigs& db_configs, const PersonsData& persons_data) {
    DBConnector connector(db_configs.db_allow_exceptions, db_configs.db_log_level);
    DBHandler db;
    if (db_configs.db_name.starts_with("tmp."s)) {
        db = connector.ConnectTmp(db_configs.db_name, db_configs.db_connection_timeout);
    } else {
        db = connector.Connect(db_configs.db_name, db_configs.db_connection_timeout);
    }
    if (!db_configs.db_allow_exceptions && !db.IsOK()) {
        return {};
    }

    ostringstream query_str;
    query_str << "from Persons "s
              << "select Name, Age "s
              << "where Age between "s << persons_data.min_age << " and "s << persons_data.max_age << " "s
              << "and Name like '%"s << db.Quote(persons_data.name_filter) << "%'"s;
    DBQuery query(query_str.str());

    vector<Person> persons;
    for (auto [name, age] : db.LoadRows<string, int>(query)) {
        persons.push_back({move(name), age});
    }
    return std::make_unique<vector<Person>>(persons);
}

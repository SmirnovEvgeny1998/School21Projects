CREATE OR REPLACE FUNCTION func_minimum(arr anyarray)
  RETURNS anyelement LANGUAGE sql AS
'SELECT min(i) FROM unnest($1) i';
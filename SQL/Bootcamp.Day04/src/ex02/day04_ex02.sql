CREATE VIEW v_generated_dates AS
SELECT generated_date::DATE FROM generate_series('2022-01-01'::DATE, '2022-01-31'::DATE, interval '1 day') AS generated_date;


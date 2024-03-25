CREATE TABLE firma (
    id INTEGER NOT NULL,
    nazwa VARCHAR2(100) NOT NULL,
    reigon Char(20) NOT NULL,
    nip Char(20) NOT NUll,
    ulica Char(20) VARCHAR2 NOT NUll,
    kod_pocztowy Char(5) NOT NULL,
    miasto VARCHAR2(100) NOT NUll,
    email VARCHAR2(100) VARCHAR2 NOT NUll,
);

ALTER TABLE firma ADD CONSTRAINT firma_pk PRIMARY KEY ( id );

CREATE TABLE faktura (
    id INTEGER NOT NULL,
    numer Char(50) NOT NULL,
    data_wystawienia Date NOT NULL,
    data_platnosci Date NOT NUll,
);

ALTER TABLE firma ADD CONSTRAINT faktura_pk PRIMARY KEY ( id );


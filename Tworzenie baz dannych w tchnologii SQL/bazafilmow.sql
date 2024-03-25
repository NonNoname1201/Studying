CREATE TABLE film (
    id               INTEGER NOT NULL,
    tytul_oryginalny VARCHAR2(200) NOT NULL,
    rok_produkcji    NUMBER(4) NOT NULL
);

ALTER TABLE film ADD CONSTRAINT film_pk PRIMARY KEY ( id );

CREATE TABLE funkcja (
    id        INTEGER NOT NULL,
    id_film   INTEGER NOT NULL,
    id_osoba  INTEGER NOT NULL,
    id_rodzaj INTEGER NOT NULL
);

ALTER TABLE funkcja ADD CONSTRAINT funkcja_pk PRIMARY KEY ( id );

CREATE TABLE ocena (
    id        INTEGER NOT NULL,
    wartosc   NUMBER(5, 2),
    id_film   INTEGER NOT NULL,
    id_zrodlo INTEGER NOT NULL
);

ALTER TABLE ocena ADD CONSTRAINT ocena_pk PRIMARY KEY ( id );

CREATE TABLE osoba (
    id       INTEGER NOT NULL,
    imie     VARCHAR2(20) NOT NULL,
    nazwisko VARCHAR2(50)
);

ALTER TABLE osoba ADD CONSTRAINT osoba_pk PRIMARY KEY ( id );

CREATE TABLE rodzaj_funkcji (
    id    INTEGER NOT NULL,
    nazwa VARCHAR2(50) NOT NULL
);

ALTER TABLE rodzaj_funkcji ADD CONSTRAINT rodzaj_funkcji_pk PRIMARY KEY ( id );

CREATE TABLE rola (
    id       INTEGER NOT NULL,
    nazwa    VARCHAR2(100) NOT NULL,
    id_film  INTEGER NOT NULL,
    id_osoba INTEGER NOT NULL
);

ALTER TABLE rola ADD CONSTRAINT rola_pk PRIMARY KEY ( id );

CREATE TABLE zrodlo (
    id    INTEGER NOT NULL,
    nazwa VARCHAR2(50) NOT NULL
);

ALTER TABLE zrodlo ADD CONSTRAINT zrodlo_pk PRIMARY KEY ( id );

ALTER TABLE funkcja
    ADD CONSTRAINT funkcja_film_fk FOREIGN KEY ( id_film )
        REFERENCES film ( id )
            ON DELETE CASCADE;

ALTER TABLE funkcja
    ADD CONSTRAINT funkcja_osoba_fk FOREIGN KEY ( id_osoba )
        REFERENCES osoba ( id )
            ON DELETE CASCADE;

ALTER TABLE funkcja
    ADD CONSTRAINT funkcja_rodzaj_funkcji_fk FOREIGN KEY ( id_rodzaj )
        REFERENCES rodzaj_funkcji ( id )
            ON DELETE CASCADE;

ALTER TABLE ocena
    ADD CONSTRAINT ocena_film_fk FOREIGN KEY ( id_film )
        REFERENCES film ( id )
            ON DELETE CASCADE;

ALTER TABLE ocena
    ADD CONSTRAINT ocena_zrodlo_fk FOREIGN KEY ( id_zrodlo )
        REFERENCES zrodlo ( id )
            ON DELETE CASCADE;

ALTER TABLE rola
    ADD CONSTRAINT rola_film_fk FOREIGN KEY ( id_film )
        REFERENCES film ( id )
            ON DELETE CASCADE;

ALTER TABLE rola
    ADD CONSTRAINT rola_osoba_fk FOREIGN KEY ( id_osoba )
        REFERENCES osoba ( id )
            ON DELETE CASCADE;

CREATE SEQUENCE film_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER film_id_trg BEFORE
    INSERT ON film
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := film_id_seq.nextval;
END;
/

CREATE SEQUENCE funkcja_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER funkcja_id_trg BEFORE
    INSERT ON funkcja
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := funkcja_id_seq.nextval;
END;
/

CREATE SEQUENCE ocena_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER ocena_id_trg BEFORE
    INSERT ON ocena
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := ocena_id_seq.nextval;
END;
/

CREATE SEQUENCE osoba_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER osoba_id_trg BEFORE
    INSERT ON osoba
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := osoba_id_seq.nextval;
END;
/

CREATE SEQUENCE rodzaj_funkcji_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER rodzaj_funkcji_id_trg BEFORE
    INSERT ON rodzaj_funkcji
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := rodzaj_funkcji_id_seq.nextval;
END;
/

CREATE SEQUENCE rola_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER rola_id_trg BEFORE
    INSERT ON rola
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := rola_id_seq.nextval;
END;
/

CREATE SEQUENCE zrodlo_id_seq START WITH 1 NOCACHE ORDER;

CREATE OR REPLACE TRIGGER zrodlo_id_trg BEFORE
    INSERT ON zrodlo
    FOR EACH ROW
    WHEN ( new.id IS NULL )
BEGIN
    :new.id := zrodlo_id_seq.nextval;
END;
/

Napisz krewede wyswietlajaca wszystkie kolumny z tabeli film, osoba, rola, rodzaj_funkcji, zrodlo i funkcja.

SELECT f.tytul, o.imie, o.nazwisko, r.nazwa, rf.nazwa, z.nazwa, fu.nazwa




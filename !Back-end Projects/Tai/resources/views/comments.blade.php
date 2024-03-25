<body>
<div class="table-container">
    <div class="title">
        <h3>Księga komentarzy</h3>
    </div>
    @if ($errors->any())
        <div class="alert alert-danger">
            <strong>Ups!</strong> Wystąpiły problemy z twoim wpisem.<br><br>
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}<br></li>
                @endforeach
            </ul>
        </div>
    @endif
    <div class="box box-primary ">
        <!-- /.box-header -->
        <!-- form start -->
        <form role="form" action="{{route('store')}}" id="comment-form"
              method="post" enctype="multipart/form-data">
            {{ csrf_field() }}
        <div class="box">
            <div class="box-body">
                <div class="form-group{{$errors->has('message')?'has-error':''}}"
                     id="roles_box">
                    <label><b>Treść</b></label> <br>
                    <textarea name="message" id="message" cols="20" rows="3" required
                              placeholder="Wpisz treść komentarza"></textarea>
                </div>
            </div>
        </div>
        <div class="box-footer">
            <button type="submit" class="btn btn-success">Utwórz</button>
        </div>
        </form>
    </div>
    @auth
        <table data-toggle="table">
            <thead>
            </thead>
            <tbody>
                @foreach($comments as $comment)
                    <tr>
                        <td>{{$comment->id}}</td>
                        <td>{{$comment->user->name}}</td>
                        <td>{{$comment->created_at}}</td>
                        <td>{{$comment->message}}</td>
                    </tr>
                @endforeach
            </tbody>
        </table>
        <div class="footer-button">
            <a href="{{ route('create') }}" class="btn btn-secondary">Dodaj</a>
        </div>
        <br>
    @endauth
</div>
@guest
    <div class="table-container">
        <b>Zaloguj się aby przejrzeć komentarze.</b>
    </div> @endguest
</body>
